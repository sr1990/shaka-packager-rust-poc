# Rust Integration with Shaka Packager

This proof of concept explores the integration of the Shaka Packager SDK with a Rust project, leveraging autocxx for C++ to Rust interoperability.

# Project Structure

-   **Shaka Packager Integration**:  The PoC contains Shaka Packager included as a Git submodule. This integration ensures that the Rust project has direct access to the latest features and updates from the Shaka Packager codebase.
-   **Rust Project**:  A simple Rust project is set up to execute a straightforward job utilizing the Shaka Packager. This serves as a real-world example of how Rust can interact with C++ libraries and SDKs.
-   **Static Library Generation**:  A  setup script is part of the project, designed to compile the Shaka Packager into a static library (`shakapackager.a`). This script uses the `ar` tool to combine object files into a single static library, ensuring that all symbols are available and correctly resolved.
-   **Rust Wrappers**: To bridge the gap between the Rust project and the Shaka Packager SDK, the Rust codebase includes custom wrappers. These wrappers adapt the SDK's structures for compatibility with `autocxx`, adding necessary setters and getters to the structs. This step is crucial for `autocxx` to generate the appropriate bindings, allowing Rust code to interact with the SDK's functionalities efficiently.

## Steps
1. Run shaka-lib-setup.sh that will get shaka-packager, build it, copy libshakapackager.mri into shaka-packager/build/packager directory and use ar tool to create libshakapackager.a.
2. Check if libshakapackager.a is created.
3. Go to root directory where build.rs is located and 
cargo clean && cargo run
4. Above should create a h264Sintel.mpd and a folder called h264_1280p containing init and media segments.	
