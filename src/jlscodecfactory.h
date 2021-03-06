//
// (C) CharLS Team 2014, all rights reserved. See the accompanying "License.txt" for licensed use.
//

#ifndef CHARLS_JLS_CODEC_FACTORY
#define CHARLS_JLS_CODEC_FACTORY

#include <memory>

struct JlsParameters;
struct JpegLSPresetCodingParameters;

template<typename Strategy>
class JlsCodecFactory
{
public:
    std::unique_ptr<Strategy> CreateCodec(const JlsParameters& params, const JpegLSPresetCodingParameters& presets);

private:
    std::unique_ptr<Strategy> CreateOptimizedCodec(const JlsParameters& params);
};

#endif
