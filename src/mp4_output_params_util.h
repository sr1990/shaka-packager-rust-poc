#pragma once

#include <iostream>
#include <sstream>
#include "packager/mp4_output_params.h"

class Mp4OutputParamsWrapper {
    public:
        Mp4OutputParams m_mp4_output_params;

        Mp4OutputParams get_mp4_output_params() { return m_mp4_output_params; }

        // Setters
        void set_include_pssh_in_stream(bool value) { m_mp4_output_params.include_pssh_in_stream = value; }
        void set_generate_sidx_in_media_segments(bool value) { m_mp4_output_params.generate_sidx_in_media_segments = value; }
        void set_low_latency_dash_mode(bool value) { m_mp4_output_params.low_latency_dash_mode = value; }

        // Getters
        bool get_include_pssh_in_stream() const { return m_mp4_output_params.include_pssh_in_stream; }
        bool get_generate_sidx_in_media_segments() const { return m_mp4_output_params.generate_sidx_in_media_segments; }
        bool get_low_latency_dash_mode() const { return m_mp4_output_params.low_latency_dash_mode; }

        // Print Mp4OutputParams
        void print_mp4_output_params() const {
            std::cout << "\nMP4 Output Params:";
            std::cout << "\nInclude PSSH in Stream: " << (m_mp4_output_params.include_pssh_in_stream ? "true" : "false");
            std::cout << "\nGenerate SIDX in Media Segments: " << (m_mp4_output_params.generate_sidx_in_media_segments ? "true" : "false");
            std::cout << "\nLow Latency DASH Mode: " << (m_mp4_output_params.low_latency_dash_mode ? "true" : "false");
        }
};