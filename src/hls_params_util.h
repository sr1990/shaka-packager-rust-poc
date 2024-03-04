#pragma once

#include <iostream>
#include <sstream>
#include "packager/hls_params.h"

using namespace shaka;

class HlsParamsWrapper {
    public:
        HlsParams m_hls_params;
        HlsParams get_hls_params() { return m_hls_params; }

        // Setters
        void set_playlist_type(HlsPlaylistType type) { m_hls_params.playlist_type = type; }
        void set_master_playlist_output(const std::string& output) { m_hls_params.master_playlist_output = output; }
        void set_base_url(const std::string& url) { m_hls_params.base_url = url; }
        void set_time_shift_buffer_depth(double depth) { m_hls_params.time_shift_buffer_depth = depth; }
        void set_preserved_segments_outside_live_window(size_t segments) { m_hls_params.preserved_segments_outside_live_window = segments; }
        void set_key_uri(const std::string& uri) { m_hls_params.key_uri = uri; }
        void set_default_language(const std::string& language) { m_hls_params.default_language = language; }
        void set_default_text_language(const std::string& language) { m_hls_params.default_text_language = language; }
        void set_is_independent_segments(bool independent) { m_hls_params.is_independent_segments = independent; }
        void set_target_segment_duration(double duration) { m_hls_params.target_segment_duration = duration; }
        void set_media_sequence_number(uint32_t number) { m_hls_params.media_sequence_number = number; }
        void set_start_time_offset(std::optional<double> offset) { m_hls_params.start_time_offset = offset; }

        // Getters
        HlsPlaylistType get_playlist_type() const { return m_hls_params.playlist_type; }
        std::string get_master_playlist_output() const { return m_hls_params.master_playlist_output; }
        std::string get_base_url() const { return m_hls_params.base_url; }
        double get_time_shift_buffer_depth() const { return m_hls_params.time_shift_buffer_depth; }
        size_t get_preserved_segments_outside_live_window() const { return m_hls_params.preserved_segments_outside_live_window; }
        std::string get_key_uri() const { return m_hls_params.key_uri; }
        std::string get_default_language() const { return m_hls_params.default_language; }
        std::string get_default_text_language() const { return m_hls_params.default_text_language; }
        bool get_is_independent_segments() const { return m_hls_params.is_independent_segments; }
        double get_target_segment_duration() const { return m_hls_params.target_segment_duration; }
        uint32_t get_media_sequence_number() const { return m_hls_params.media_sequence_number; }
        std::optional<double> get_start_time_offset() const { return m_hls_params.start_time_offset; }

        // Method to print HLS Params
        void print_hls_params() const {
        std::cout << "HLS Params:\n";
        std::cout << "Playlist Type: ";
        switch (m_hls_params.playlist_type) {
            case HlsPlaylistType::kVod: std::cout << "VOD"; break;
            case HlsPlaylistType::kEvent: std::cout << "Event"; break;
            case HlsPlaylistType::kLive: std::cout << "Live"; break;
            default: std::cout << "Unknown"; // It's a good practice to handle potentially unknown values
        }
        std::cout << "\nMaster Playlist Output: " << m_hls_params.master_playlist_output;
        std::cout << "\nBase URL: " << m_hls_params.base_url;
        std::cout << "\nTime Shift Buffer Depth: " << m_hls_params.time_shift_buffer_depth;
        std::cout << "\nPreserved Segments Outside Live Window: " << m_hls_params.preserved_segments_outside_live_window;
        std::cout << "\nKey URI: " << m_hls_params.key_uri;
        std::cout << "\nDefault Language: " << m_hls_params.default_language;
        std::cout << "\nDefault Text Language: " << m_hls_params.default_text_language;
        std::cout << "\nIs Independent Segments: " << (m_hls_params.is_independent_segments ? "true" : "false");
        std::cout << "\nTarget Segment Duration: " << m_hls_params.target_segment_duration;
        std::cout << "\nMedia Sequence Number: " << m_hls_params.media_sequence_number;
        if (m_hls_params.start_time_offset.has_value()) {
            std::cout << "\nStart Time Offset: " << m_hls_params.start_time_offset.value();
        } else {
            std::cout << "\nStart Time Offset: not set";
        }
  }
};
