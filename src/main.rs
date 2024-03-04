use autocxx::prelude::*;
use std::env;

include_cpp! {
    #include "packager/packager.h"
    #include "packager/version/version.h"
    #include "packager_util.h"
    #include "chunking_params_util.h"
    #include "mpd_params_util.h"
    #include "mp4_output_params_util.h"
    #include "hls_params_util.h"
    // Safety policy. We are marking that this whole C++ inclusion is unsafe
    // which means the functions themselves do not need to be marked
    // as unsafe. Other policies are possible.
    safety!(unsafe_ffi)
    generate!("shaka::Packager")
    generate!("shaka::TestParams")
    generate!("shaka::ChunkingParams")
    generate!("shaka::PackagingParams")
    generate!("shaka::Mp4OutputParams")
    generate!("shaka::AdCueGeneratorParams")
    generate!("shaka::MpdParams")
    generate!("shaka::HlsParams")
    generate!("shaka::EncryptionParams")
    generate!("shaka::DecryptionParams")
    generate!("shaka::BufferCallbackParams")
    generate!("shaka::Status")
    generate!("ChunkingParamsWrapper")
    generate!("PackagingParamsWrapper")
    generate!("MpdParamsWrapper")
    generate!("StreamDescriptorWrapper")
    generate!("Mp4OutputParamsWrapper")
    generate!("HlsParamsWrapper")
    generate!("TestParamsWrapper")
}

fn main() {

    // Get library version.
    let library_version = ffi::shaka::Packager::GetLibraryVersion().to_string();
    println!("Shaka packager library Version: {:#?}", library_version);

    println!("Testing shaka packager.");
    println!("Trying out the following
            ../packager \
            'in=Sintel-1280x720.mp4,stream=video,init_segment=h264_1280p/init.mp4,segment_template=h264_1280p/$Number$.m4s' \
            --mpd_output ./h264Sintel.mpd --generate_static_live_mpd");

    // 1. Create ChunkingParams.
    println!("1. Create ChunkingParams.");
    let mut chunking_param_wrapper = ffi::ChunkingParamsWrapper::new().within_unique_ptr();
    chunking_param_wrapper.pin_mut().set_segment_duration_in_seconds(10.0);
    chunking_param_wrapper.pin_mut().print_chunking_params();
    let chunking_params = chunking_param_wrapper.pin_mut().get_chunking_params().within_unique_ptr();

    // 2. Create MpdParams.
    println!("2. Create MpdParams.");
    let mut mpd_params_wrapper = ffi::MpdParamsWrapper::new().within_unique_ptr();
    mpd_params_wrapper.pin_mut().set_mpd_output("./h264Sintel.mpd");
    mpd_params_wrapper.pin_mut().set_generate_static_live_mpd(true);
    mpd_params_wrapper.pin_mut().print_mpd_params();
    let mpd_params = mpd_params_wrapper.pin_mut().get_mpd_params().within_unique_ptr();

    // 3. Create PackagingParams.
    println!("3. Create PackagingParams.");
    let mut packaging_params_wrapper = ffi::PackagingParamsWrapper::new().within_unique_ptr(); 
    packaging_params_wrapper.pin_mut().set_chunking_params(chunking_params);
    packaging_params_wrapper.pin_mut().set_mpd_params(mpd_params);
    packaging_params_wrapper.pin_mut().printPackagingParams();
    let packaging_params = packaging_params_wrapper.pin_mut().get_packaging_params().within_unique_ptr(); 

    // 4. Create StreamDescriptor.
    println!("4. Create StreamDescriptor.");
    let mut stream_descriptor_wrapper = ffi::StreamDescriptorWrapper::new().within_unique_ptr();
    stream_descriptor_wrapper.pin_mut().set_stream_selector("video");
    let path = env::current_dir().unwrap();
    let input_media_path = path.display().to_string() + "/Sintel-1280x720.mp4";
    stream_descriptor_wrapper.pin_mut().set_input(input_media_path);
    stream_descriptor_wrapper.pin_mut().set_output("h264_1280p/init.mp4");
    stream_descriptor_wrapper.pin_mut().set_segment_template("h264_1280p/$Number$.m4s");
    
    let stream_descriptor1 = stream_descriptor_wrapper.pin_mut().get_stream_desriptor().within_unique_ptr();

    // 5. Create StreamDescriptor array.
    println!("5. Create StreamDescriptor array.");
    let mut stream_descriptor_vector = ffi::StreamDescriptorWrapper::get_stream_descriptor_vec();
    println!("Stream descriptor vector array len: {}", stream_descriptor_vector.len());
    ffi::StreamDescriptorWrapper::add_to_vec(stream_descriptor_vector.pin_mut(), stream_descriptor1);
    println!("Stream descriptor vector array len: {}", stream_descriptor_vector.len());


    // 6. Create packager instance.
    println!("6. Create packager instance.");
    let mut packager = ffi::shaka::Packager::new().within_unique_ptr();
    
    // 7. Initialize packager.
    println!("7. Initialize packager.");
    let mut init_packager_status = 
        packager.pin_mut().Initialize(&packaging_params, &stream_descriptor_vector).within_unique_ptr();
    
    println!("Initialize packager result: ");
    if init_packager_status.pin_mut().ok() {
        println!("Packager initialize: ok");
        println!("{}", init_packager_status.pin_mut().ToString());
    } else {
        println!("not ok");
    }

    // 8. Run packager job.
    println!("8. Run packager job.");
    let mut run_packager_status = packager.pin_mut().Run().within_unique_ptr();    

    println!("Run packager result:"); 
    if run_packager_status.pin_mut().ok() {
        println!("ok");
        println!("{}", run_packager_status.pin_mut().ToString());
    } else {
        println!("not ok");
    }

}
