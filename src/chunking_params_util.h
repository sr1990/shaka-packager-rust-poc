#pragma once

#include <iostream>
#include <sstream>
#include "packager/chunking_params.h"

using namespace shaka;
class ChunkingParamsWrapper {
    public:
        ChunkingParams m_chunking_params;
        ChunkingParamsWrapper() {}
        ChunkingParams get_chunking_params() { return m_chunking_params; }

        // Setters
        void set_segment_duration_in_seconds(double value) { m_chunking_params.segment_duration_in_seconds = value; }
        void set_subsegment_duration_in_seconds(double value) {
            if (value <= m_chunking_params.segment_duration_in_seconds) {
                m_chunking_params.subsegment_duration_in_seconds = value;
            } else {
                std::cerr << "Subsegment duration cannot be larger than segment duration." << std::endl;
            }
        }
        void set_segment_sap_aligned(bool value) { m_chunking_params.segment_sap_aligned = value; }
        void set_subsegment_sap_aligned(bool value) { m_chunking_params.subsegment_sap_aligned = value; }
        void set_low_latency_dash_mode(bool value) { m_chunking_params.low_latency_dash_mode = value; }

        // Getters
        double get_segment_duration_in_seconds() const { return m_chunking_params.segment_duration_in_seconds; }
        double get_subsegment_duration_in_seconds() const { return m_chunking_params.subsegment_duration_in_seconds; }
        bool get_segment_sap_aligned() const { return m_chunking_params.segment_sap_aligned; }
        bool get_subsegment_sap_aligned() const { return m_chunking_params.subsegment_sap_aligned; }
        bool get_low_latency_dash_mode() const { return m_chunking_params.low_latency_dash_mode; }

        // Print chunking params
        void print_chunking_params() const {
            std::cout << "\nChunkingParams";
            std::cout << "\nSegment Duration in Seconds: " << m_chunking_params.segment_duration_in_seconds;
            std::cout << "\nSubsegment Duration in Seconds: " << m_chunking_params.subsegment_duration_in_seconds;
            std::cout << "\nSegment SAP Aligned: " << (m_chunking_params.segment_sap_aligned ? "true" : "false");
            std::cout << "\nSubsegment SAP Aligned: " << (m_chunking_params.subsegment_sap_aligned ? "true" : "false");
            std::cout << "\nLow Latency Dash Mode: " << (m_chunking_params.low_latency_dash_mode ? "true" : "false");
        }

};