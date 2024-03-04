fn main() -> miette::Result<()> {
    // It's necessary to use an absolute path here because the
    // C++ codegen and the macro codegen appears to be run from different
    // working directories.
    let path = std::path::PathBuf::from("shaka-packager");
    let path2 = std::path::PathBuf::from("src");
    let path3 = std::path::PathBuf::from("shaka-packager/include");
    let path4 = std::path::PathBuf::from("shaka-packager/packager");
    
    let mut b = autocxx_build::Builder::new("src/main.rs", 
    &[&path, &path2, &path3, &path4])
            .extra_clang_args(&[
                "-std=c++17", 
                "-I /usr/local/include",
                ]).build().unwrap();
    b.flag_if_supported("-std=c++17")
        .compile("shaka-packager");
    println!("cargo:rerun-if-changed=src/main.rs");
    println!("cargo:rustc-link-search=native=shaka-packager/build/packager/");
    println!("cargo:rustc-link-lib=static=shakapackager");
    Ok(())
}
