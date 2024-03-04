#pragma once

#include <iostream>
#include <sstream>
#include "packager/mpd_params.h"

using namespace shaka;

class MpdParamsWrapper {
    public:
        MpdParams m_mpd_params;
        MpdParams get_mpd_params() { return m_mpd_params; }
        
        // Setters
        void set_mpd_output(const std::string value) { m_mpd_params.mpd_output = value; }
        void set_base_urls(const std::vector<std::string>& value) { m_mpd_params.base_urls = value; }
        void add_to_base_urls(std::string base_url) {m_mpd_params.base_urls.push_back(base_url); }
        void set_min_buffer_time(double value) { m_mpd_params.min_buffer_time = value; }
        void set_minimum_update_period(double value) { m_mpd_params.minimum_update_period = value; }
        void set_suggested_presentation_delay(double value) { m_mpd_params.suggested_presentation_delay = value; }
        void set_time_shift_buffer_depth(double value) { m_mpd_params.time_shift_buffer_depth = value; }
        void set_preserved_segments_outside_live_window(size_t value) { m_mpd_params.preserved_segments_outside_live_window = value; }
        void add_to_utc_timings(MpdParams::UtcTiming utc_timing) { m_mpd_params.utc_timings.push_back(utc_timing); }
        void set_default_language(const std::string value) { m_mpd_params.default_language = value; }
        void set_default_text_language(const std::string value) { m_mpd_params.default_text_language = value; }
        void set_generate_static_live_mpd(bool value) { m_mpd_params.generate_static_live_mpd = value; }
        void set_generate_dash_if_iop_compliant_mpd(bool value) { m_mpd_params.generate_dash_if_iop_compliant_mpd = value; }
        void set_allow_approximate_segment_timeline(bool value) { m_mpd_params.allow_approximate_segment_timeline = value; }
        void set_target_segment_duration(double value) { m_mpd_params.target_segment_duration = value; }
        void set_allow_codec_switching(bool value) { m_mpd_params.allow_codec_switching = value; }
        void set_include_mspr_pro(bool value) { m_mpd_params.include_mspr_pro = value; }
        void set_use_segment_list(bool value) { m_mpd_params.use_segment_list = value; }
        void set_low_latency_dash_mode(bool value) { m_mpd_params.low_latency_dash_mode = value; }
        void set_target_latency_seconds(double value) { m_mpd_params.target_latency_seconds = value; }

        // Getters
        std::string get_mpd_output() const { return m_mpd_params.mpd_output; }
        std::vector<std::string> get_base_urls() const { return m_mpd_params.base_urls; }
        double get_min_buffer_time() const { return m_mpd_params.min_buffer_time; }
        double get_minimum_update_period() const { return m_mpd_params.minimum_update_period; }
        double get_suggested_presentation_delay() const { return m_mpd_params.suggested_presentation_delay; }
        double get_time_shift_buffer_depth() const { return m_mpd_params.time_shift_buffer_depth; }
        size_t get_preserved_segments_outside_live_window() const { return m_mpd_params.preserved_segments_outside_live_window; }
        std::vector<MpdParams::UtcTiming> get_utc_timings() { return m_mpd_params.utc_timings; }
        std::string get_default_language() const { return m_mpd_params.default_language; }
        std::string get_default_text_language() const { return m_mpd_params.default_text_language; }
        bool get_generate_static_live_mpd() const { return m_mpd_params.generate_static_live_mpd; }
        bool get_generate_dash_if_iop_compliant_mpd() const { return m_mpd_params.generate_dash_if_iop_compliant_mpd; }
        bool get_allow_approximate_segment_timeline() const { return m_mpd_params.allow_approximate_segment_timeline; }
        double get_target_segment_duration() const { return m_mpd_params.target_segment_duration; }
        bool get_allow_codec_switching() const { return m_mpd_params.allow_codec_switching; }
        bool get_include_mspr_pro() const { return m_mpd_params.include_mspr_pro; }
        bool get_use_segment_list() const { return m_mpd_params.use_segment_list; }
        bool get_low_latency_dash_mode() const { return m_mpd_params.low_latency_dash_mode; }
        double get_target_latency_seconds() const { return m_mpd_params.target_latency_seconds; }

        // Print method
        void print_mpd_params() const {
            std::cout << "MPD Output: " << m_mpd_params.mpd_output << "\n";
            std::cout << "Base URLs: ";
            for (const auto& url : m_mpd_params.base_urls) { std::cout << url << " "; }
            std::cout << "\nMin Buffer Time: " << m_mpd_params.min_buffer_time;
            std::cout << "\nMinimum Update Period: " << m_mpd_params.minimum_update_period;
            std::cout << "\nSuggested Presentation Delay: " << m_mpd_params.suggested_presentation_delay;
            std::cout << "\nTime Shift Buffer Depth: " << m_mpd_params.time_shift_buffer_depth;
            std::cout << "\nPreserved Segments Outside Live Window: " << m_mpd_params.preserved_segments_outside_live_window;
            std::cout << "\nUTC Timings:";
            for (const auto& utc_timing : m_mpd_params.utc_timings) {
                std::cout << " Scheme ID URI: " << utc_timing.scheme_id_uri << ", Value: " << utc_timing.value;
            }
            std::cout << "\nDefault Language: " << m_mpd_params.default_language;
            std::cout << "\nDefault Text Language: " << m_mpd_params.default_text_language;
            std::cout << "\nGenerate Static Live MPD: " << m_mpd_params.generate_static_live_mpd;
            std::cout << "\nGenerate DASH-IF IOP Compliant MPD: " << m_mpd_params.generate_dash_if_iop_compliant_mpd;
            std::cout << "\nAllow Approximate Segment Timeline: " << m_mpd_params.allow_approximate_segment_timeline;
            std::cout << "\nTarget Segment Duration: " << m_mpd_params.target_segment_duration;
            std::cout << "\nAllow Codec Switching: " << m_mpd_params.allow_codec_switching;
            std::cout << "\nInclude MSPR PRO: " << m_mpd_params.include_mspr_pro;
            std::cout << "\nUse Segment List: " << m_mpd_params.use_segment_list;
            std::cout << "\nLow Latency Dash Mode: " << m_mpd_params.low_latency_dash_mode;
            std::cout << "\nTarget Latency Seconds: " << m_mpd_params.target_latency_seconds << "\n";
        } 
};