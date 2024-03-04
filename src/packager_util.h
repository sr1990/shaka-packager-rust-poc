#pragma once

#include <iostream>
#include <sstream>
#include <cstdint>
#include <vector>
#include "packager/packager.h"
#include "packager/chunking_params.h"
#include "chunking_params_util.h"

using namespace shaka;

class TestParamsWrapper {
    public:
    TestParams m_test_params;
    TestParamsWrapper() {
        m_test_params.injected_library_version = "TestParamsWrapper -lib 1";
    }

    static TestParamsWrapper new_test_params(bool dump_stream_info, 
		  		                             bool inject_fake_clock,
				                             std::string injected_library_version) {
	    TestParamsWrapper test_params_wrapper;
        test_params_wrapper.m_test_params.dump_stream_info = dump_stream_info;
	    test_params_wrapper.m_test_params.inject_fake_clock = inject_fake_clock;
	    test_params_wrapper.m_test_params.injected_library_version = injected_library_version;
        return test_params_wrapper;
    }  

    // Get TestParams 
    TestParams get_test_params() { return m_test_params;}
    
    // Setters
    void set_dump_stream_info(bool value) { m_test_params.dump_stream_info = value; }
    void set_inject_fake_clock(bool value) { m_test_params.inject_fake_clock = value; }
    void set_injected_library_version(std::string value) { m_test_params.injected_library_version = value;}
    
    // Getters
    bool get_dump_stream_info() const { return m_test_params.dump_stream_info;}
    bool get_inject_fake_clock() const { return m_test_params.inject_fake_clock;}
    std::string get_injected_library_version() const { return m_test_params.injected_library_version;}
    
    void print_test_params() {
        std::cout<<"\nTestParams: ";
        std::cout<<"\ndump_stream_info: " << (m_test_params.dump_stream_info ? "true" : "false");
        std::cout<<"\ninject_fake_clock: " << (m_test_params.inject_fake_clock ? "true" : "false");
        std::cout<<"\nInjected library version: " << m_test_params.injected_library_version << std::endl;
    }
};

class PackagingParamsWrapper {
    public:
    PackagingParams m_packaging_params;
    
    PackagingParams get_packaging_params() {
        return m_packaging_params;
    }    

    PackagingParamsWrapper() {}

    // Setters
    void set_temp_dir(const std::string temp_dir) {
        m_packaging_params.temp_dir = temp_dir;
    }
    void set_mp4_output_params(const Mp4OutputParams params) {
        m_packaging_params.mp4_output_params = params;
    }
    void set_transport_stream_timestamp_offset_ms(int32_t offset_ms) {
        m_packaging_params.transport_stream_timestamp_offset_ms = offset_ms;
    }
    void set_default_text_zero_bias_ms(int32_t bias_ms) {
        m_packaging_params.default_text_zero_bias_ms = bias_ms;
    }
    void set_chunking_params(const ChunkingParams params) {
        m_packaging_params.chunking_params = params;
    }
    void set_output_media_info(bool output_media_info) {
        m_packaging_params.output_media_info = output_media_info;
    }
    void set_single_threaded(bool single_threaded) {
        m_packaging_params.single_threaded = single_threaded;
    }
    void set_mpd_params(const MpdParams params) {
        m_packaging_params.mpd_params = params;
    }
    void set_hls_params(const HlsParams params) {
        m_packaging_params.hls_params = params;
    }

    // Getters
    std::string get_temp_dir() const {
        return m_packaging_params.temp_dir;
    }
    Mp4OutputParams get_mp4_output_params() const {
        return m_packaging_params.mp4_output_params;
    }
    int32_t get_transport_stream_timestamp_offset_ms() const {
        return m_packaging_params.transport_stream_timestamp_offset_ms;
    }
    int32_t get_default_text_zero_bias_ms() const {
        return m_packaging_params.default_text_zero_bias_ms;
    }
    ChunkingParams get_chunking_params() const {
        return m_packaging_params.chunking_params;
    }
    bool get_output_media_info() const {
        return m_packaging_params.output_media_info;
    }
    bool get_single_threaded() const {
        return m_packaging_params.single_threaded;
    }
    MpdParams get_mpd_params() const {
        return m_packaging_params.mpd_params;
    }
    HlsParams get_hls_params() const {
        return m_packaging_params.hls_params;
    }

    void printPackagingParams() {
        std::cout <<"\n Packaging Params: ";

        std::cout <<"\n Chunking Params: ";
        std::cout <<"\nSegment Duration in seconds: " << m_packaging_params.chunking_params.segment_duration_in_seconds;
        std::cout <<"\nSubSegment Duration in seconds: " << m_packaging_params.chunking_params.subsegment_duration_in_seconds;       
    
        std::cout <<"\n MpdParams: ";
        std::cout <<"\n mpd_output: " << m_packaging_params.mpd_params.mpd_output;
        std::cout <<"\n generate_static_live_mpd: " << m_packaging_params.mpd_params.generate_static_live_mpd<<std::endl;
    }    
};

class StreamDescriptorWrapper {
    public:
        StreamDescriptor m_stream_descriptor;
        
        // Get StreamDescriptor 
        StreamDescriptor get_stream_desriptor() { return m_stream_descriptor; }

        // Setters
        void set_index(std::optional<uint32_t> index) { m_stream_descriptor.index = index; }
        void set_input(const std::string input) { m_stream_descriptor.input = input; }
        void set_stream_selector(const std::string selector) { m_stream_descriptor.stream_selector = selector; }
        void set_output(const std::string output) { m_stream_descriptor.output = output; }
        void set_segment_template(const std::string template_) { m_stream_descriptor.segment_template = template_; }
        void set_output_format(const std::string format) { m_stream_descriptor.output_format = format; }
        void set_skip_encryption(bool skip) { m_stream_descriptor.skip_encryption = skip; }
        void set_drm_label(const std::string label) { m_stream_descriptor.drm_label = label; }
        void set_trick_play_factor(uint32_t factor) { m_stream_descriptor.trick_play_factor = factor; }
        void set_bandwidth(uint32_t bandwidth) { m_stream_descriptor.bandwidth = bandwidth; }
        void set_language(const std::string language) { m_stream_descriptor.language = language; }
        void set_cc_index(int32_t index) { m_stream_descriptor.cc_index = index; }
        void set_hls_name(const std::string name) { m_stream_descriptor.hls_name = name; }
        void set_hls_group_id(const std::string id) { m_stream_descriptor.hls_group_id = id; }
        void set_hls_playlist_name(const std::string name) { m_stream_descriptor.hls_playlist_name = name; }
        void set_hls_iframe_playlist_name(const std::string name) { m_stream_descriptor.hls_iframe_playlist_name = name; }
        void set_hls_characteristics(const std::vector<std::string> characteristics) { m_stream_descriptor.hls_characteristics = characteristics; }
        void add_hls_characteristics(const std::string characteristic) { m_stream_descriptor.hls_characteristics.push_back(characteristic); }
        void set_dash_accessibilities(const std::vector<std::string> accessibilities) { m_stream_descriptor.dash_accessiblities = accessibilities; }
        void add_dash_accessibility(const std::string dash_accessibility) { m_stream_descriptor.dash_accessiblities.push_back(dash_accessibility); }
        void set_dash_roles(const std::vector<std::string> roles) { m_stream_descriptor.dash_roles = roles; }
        void add_dash_role(const std::string dash_role) { m_stream_descriptor.dash_roles.push_back(dash_role); }
        void set_dash_only(bool only) { m_stream_descriptor.dash_only = only; }
        void set_hls_only(bool only) { m_stream_descriptor.hls_only = only; }
        void set_forced_subtitle(bool forced) { m_stream_descriptor.forced_subtitle = forced; }
        void set_dash_label(const std::string& label) { m_stream_descriptor.dash_label = label; }

        // Getters
        std::optional<uint32_t> get_index() const { return m_stream_descriptor.index; }
        std::string get_input() const { return m_stream_descriptor.input; }
        std::string get_stream_selector() const { return m_stream_descriptor.stream_selector; }
        std::string get_output() const { return m_stream_descriptor.output; }
        std::string get_segment_template() const { return m_stream_descriptor.segment_template; }
        std::string get_output_format() const { return m_stream_descriptor.output_format; }
        bool get_skip_encryption() const { return m_stream_descriptor.skip_encryption; }
        std::string get_drm_label() const { return m_stream_descriptor.drm_label; }
        uint32_t get_trick_play_factor() const { return m_stream_descriptor.trick_play_factor; }
        uint32_t get_bandwidth() const { return m_stream_descriptor.bandwidth; }
        std::string get_language() const { return m_stream_descriptor.language; }
        int32_t get_cc_index() const { return m_stream_descriptor.cc_index; }
        std::string get_hls_name() const { return m_stream_descriptor.hls_name; }
        std::string get_hls_group_id() const { return m_stream_descriptor.hls_group_id; }
        std::string get_hls_playlist_name() const { return m_stream_descriptor.hls_playlist_name; }
        std::string get_hls_iframe_playlist_name() const { return m_stream_descriptor.hls_iframe_playlist_name; }
        std::vector<std::string> get_hls_characteristics() const { return m_stream_descriptor.hls_characteristics; }
        std::vector<std::string> get_dash_accessibilities() const { return m_stream_descriptor.dash_accessiblities; }
        std::vector<std::string> get_dash_roles() const { return m_stream_descriptor.dash_roles; }
        bool get_dash_only() const { return m_stream_descriptor.dash_only; }
        bool get_hls_only() const { return m_stream_descriptor.hls_only; }
        bool get_forced_subtitle() const { return m_stream_descriptor.forced_subtitle; }
        std::string get_dash_label() const { return m_stream_descriptor.dash_label; }        
        
        // vector related static method
        static std::vector<StreamDescriptor> get_stream_descriptor_vec() {
    	    return std::vector<StreamDescriptor>();
        }

        static void add_to_vec(std::vector<StreamDescriptor>& some_vec, StreamDescriptor a) {
            some_vec.push_back(a);
        }

        void print_stream_descriptor() const {
            std::cout << "Stream Descriptor:\n";
            if (m_stream_descriptor.index) {
                std::cout << "Index: " << *m_stream_descriptor.index << "\n";
            } else {
                std::cout << "Index: not set\n";
            }
            std::cout << "Input: " << m_stream_descriptor.input << "\n";
            std::cout << "Stream Selector: " << m_stream_descriptor.stream_selector << "\n";
            std::cout << "Output: " << m_stream_descriptor.output << "\n";
            std::cout << "Segment Template: " << m_stream_descriptor.segment_template << "\n";
            std::cout << "Output Format: " << m_stream_descriptor.output_format << "\n";
            std::cout << "Skip Encryption: " << (m_stream_descriptor.skip_encryption ? "true" : "false") << "\n";
            std::cout << "DRM Label: " << m_stream_descriptor.drm_label << "\n";
            std::cout << "Trick Play Factor: " << m_stream_descriptor.trick_play_factor << "\n";
            std::cout << "Bandwidth: " << m_stream_descriptor.bandwidth << "\n";
            std::cout << "Language: " << m_stream_descriptor.language << "\n";
            std::cout << "CC Index: " << m_stream_descriptor.cc_index << "\n";
            std::cout << "HLS Name: " << m_stream_descriptor.hls_name << "\n";
            std::cout << "HLS Group ID: " << m_stream_descriptor.hls_group_id << "\n";
            std::cout << "HLS Playlist Name: " << m_stream_descriptor.hls_playlist_name << "\n";
            std::cout << "HLS IFrame Playlist Name: " << m_stream_descriptor.hls_iframe_playlist_name << "\n";
            if (!m_stream_descriptor.hls_characteristics.empty()) {
                std::cout << "HLS Characteristics: ";
                for (const auto& characteristic : m_stream_descriptor.hls_characteristics) {
                    std::cout << characteristic << " ";
                }
                std::cout << "\n";
            }
            if (!m_stream_descriptor.dash_accessiblities.empty()) {
                std::cout << "DASH Accessibilities: ";
                for (const auto& accessibility : m_stream_descriptor.dash_accessiblities) {
                    std::cout << accessibility << " ";
                }
                std::cout << "\n";
            }
            if (!m_stream_descriptor.dash_roles.empty()) {
                std::cout << "DASH Roles: ";
                for (const auto& role : m_stream_descriptor.dash_roles) {
                    std::cout << role << " ";
                }
                std::cout << "\n";
            }
            std::cout << "DASH Only: " << (m_stream_descriptor.dash_only ? "true" : "false") << "\n";
            std::cout << "HLS Only: " << (m_stream_descriptor.hls_only ? "true" : "false") << "\n";
            std::cout << "Forced Subtitle: " << (m_stream_descriptor.forced_subtitle ? "true" : "false") << "\n";
            std::cout << "DASH Label: " << m_stream_descriptor.dash_label << "\n";
        }            

};
