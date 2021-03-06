/*
  (C) Jan de Vaan 2007-2010, all rights reserved. See the accompanying "License.txt" for licensed use.
*/
#ifndef CHARLS_PUBLIC_TYPES
#define CHARLS_PUBLIC_TYPES


#ifdef __cplusplus

#include <cstdint>
#include <cstddef>

namespace charls
{
    /// <summary>
    /// Defines the result values that are returned by the CharLS API functions.
    /// </summary>
    enum class ApiResult
    {
        OK = 0,                              // The operation completed without errors.
        InvalidJlsParameters = 1,            // One of the JLS parameters is invalid.
        ParameterValueNotSupported = 2,      // The parameter value not supported.
        UncompressedBufferTooSmall = 3,      // The uncompressed buffer is too small to hold all the output.
        CompressedBufferTooSmall = 4,        // The compressed buffer too small, more input data was expected.
        InvalidCompressedData = 5,           // This error is returned when the encoded bit stream contains a general structural problem.
        TooMuchCompressedData = 6,           // Too much compressed data.The decoding process is ready but the input buffer still contains encoded data.
        ImageTypeNotSupported = 7,           // This error is returned when the bit stream is encoded with an option that is not supported by this implementation.
        UnsupportedBitDepthForTransform = 8, // The bit depth for transformation is not supported.
        UnsupportedColorTransform = 9,       // The color transformation is not supported.
        UnsupportedEncoding = 10,            // This error is returned when an encoded frame is found that is not encoded with the JPEG-LS algorithm.
        UnknownJpegMarker = 11,              // This error is returned when an unknown JPEG marker code is detected in the encoded bit stream.
        MissingJpegMarkerStart = 12,         // This error is returned when the algorithm expect a 0xFF code (indicates start of a JPEG marker) but none was found.
        UnspecifiedFailure = 13,             // This error is returned when the implementation detected a failure, but no specific error is available.
        UnexpectedFailure = 14               // This error is returned when the implementation encountered a failure it didn't expect. No guarantees can be given for the state after this error.
    };

    /// <summary>
    /// Defines the interleave mode for multi-component (color) pixel data.
    /// </summary>
    enum class InterleaveMode
    {
        /// <summary>
        /// The data is encoded and stored as component for component: RRRGGGBBB.
        /// </summary>
        None   = 0,

        /// <summary>
        /// The interleave mode is by line. A full line of each component is encoded before moving to the next line.
        /// </summary>
        Line   = 1,

        /// <summary>
        /// The data is encoded and stored by sample. For color images this is the format like RGBRGBRGB.
        /// </summary>
        Sample = 2
    };

    /// <summary>
    /// Defines color space transformations as defined and implemented by the JPEG-LS library of HP Labs.
    /// These color space transformation decrease the correlation between the 3 color components, resulting in better encoding ratio.
    /// These options are only implemented for backwards compatibility and NOT part of the JPEG-LS standard.
    /// The JPEG-LS ISO/IEC 14495-1:1999 standard provides no capabilities to transport which color space transformation was used.
    /// </summary>
    enum class ColorTransformation
    {
        /// <summary>
        /// No color space transformation has been applied.
        /// </summary>
        None = 0,

        /// <summary>
        /// Defines the reversible lossless color transformation:
        /// G = G
        /// R = R - G
        /// B = B - G
        /// </summary>
        HP1 = 1,

        /// <summary>
        /// Defines the reversible lossless color transformation:
        /// G = G
        /// B = B - (R + G) / 2
        /// R = R - G
        /// </summary>
        HP2 = 2,

        /// <summary>
        /// Defines the reversible lossless color transformation of Y-Cb-Cr):
        /// R = R - G
        /// B = B - G
        /// G = G + (R + B) / 4
        /// </summary>
        HP3 = 3,
    };
}

using CharlsApiResultType = charls::ApiResult;
using CharlsInterleaveModeType = charls::InterleaveMode;
using CharlsColorTransformationType = charls::ColorTransformation;

// Defines the size of the char buffer that should be passed to the CharLS API to get the error message text.
const std::size_t ErrorMessageSize = 256;

#else

#include <stdint.h>

enum CharlsApiResult
{
    CHARLS_API_RESULT_OK                                  = 0,  // The operation completed without errors.
    CHARLS_API_RESULT_INVALID_JLS_PARAMETERS              = 1,  // One of the JLS parameters is invalid.
    CHARLS_API_RESULT_PARAMETER_VALUE_NOT_SUPPORTED       = 2,  // The parameter value not supported.
    CHARLS_API_RESULT_UNCOMPRESSED_BUFFER_TOO_SMALL       = 3,  // The uncompressed buffer is too small to hold all the output.
    CHARLS_API_RESULT_COMPRESSED_BUFFER_TOO_SMALL         = 4,  // The compressed buffer too small, more input data was expected.
    CHARLS_API_RESULT_INVALID_COMPRESSED_DATA             = 5,  // This error is returned when the encoded bit stream contains a general structural problem.
    CHARLS_API_RESULT_TOO_MUCH_COMPRESSED_DATA            = 6,  // Too much compressed data.The decoding process is ready but the input buffer still contains encoded data.
    CHARLS_API_RESULT_IMAGE_TYPE_NOT_SUPPORTED            = 7,  // This error is returned when the bit stream is encoded with an option that is not supported by this implementation.
    CHARLS_API_RESULT_UNSUPPORTED_BIT_DEPTH_FOR_TRANSFORM = 8,  // The bit depth for transformation is not supported.
    CHARLS_API_RESULT_UNSUPPORTED_COLOR_TRANSFORM         = 9,  // The color transformation is not supported.
    CHARLS_API_RESULT_UNSUPPORTED_ENCODING                = 10, // This error is returned when an encoded frame is found that is not encoded with the JPEG-LS algorithm.
    CHARLS_API_RESULT_UNKNOWN_JPEG_MARKER                 = 11, // This error is returned when an unknown JPEG marker code is detected in the encoded bit stream.
    CHARLS_API_RESULT_MISSING_JPEG_MARKER_START           = 12, // This error is returned when the algorithm expect a 0xFF code (indicates start of a JPEG marker) but none was found.
    CHARLS_API_RESULT_UNSPECIFIED_FAILURE                 = 13, // This error is returned when the implementation detected a failure, but no specific error is available.
    CHARLS_API_RESULT_UNEXPECTED_FAILURE                  = 14, // This error is returned when the implementation encountered a failure it didn't expect. No guarantees can be given for the state after this error.
};

enum CharlsInterleaveMode
{
    CHARLS_IM_NONE   = 0,
    CHARLS_IM_LINE   = 1,
    CHARLS_IM_SAMPLE = 2
};

enum CharlsColorTransformation
{
    CHARLS_COLOR_TRANSFORMATION_NONE = 0,
    CHARLS_COLOR_TRANSFORMATION_HP1 = 1,
    CHARLS_COLOR_TRANSFORMATION_HP2 = 2,
    CHARLS_COLOR_TRANSFORMATION_HP3 = 3,
};

typedef enum CharlsApiResult CharlsApiResultType;
typedef enum CharlsInterleaveMode CharlsInterleaveModeType;
typedef enum CharlsColorTransformation CharlsColorTransformationType;

// Defines the size of the char buffer that should be passed to the CharLS API to get the error message text.
#define CHARLS_ERROR_MESSAGE_SIZE 256

#endif


/// <summary>
/// Defines the JPEG-LS preset coding parameters as defined in ISO/IEC 14495-1, C.2.4.1.1.
/// JPEG-LS defines a default set of parameters, but custom parameters can be used.
/// When used these parameters are written into the encoded bit stream as they are needed for the decoding process.
/// </summary>
struct JpegLSPresetCodingParameters
{
    /// <summary>
    /// Maximum possible value for any image sample in a scan.
    /// This must be greater than or equal to the actual maximum value for the components in a scan.
    /// </summary>
    int MaximumSampleValue;

    /// <summary>
    /// First quantization threshold value for the local gradients.
    /// </summary>
    int Threshold1;

    /// <summary>
    /// Second quantization threshold value for the local gradients.
    /// </summary>
    int Threshold2;

    /// <summary>
    /// Third quantization threshold value for the local gradients.
    /// </summary>
    int Threshold3;

    /// <summary>
    /// Value at which the counters A, B, and N are halved.
    /// </summary>
    int ResetValue;
};


struct JlsRect
{
    int X;
    int Y;
    int Width;
    int Height;
};


/// <summary>
/// Defines the parameters for the JPEG File Interchange Format.
/// The format is defined in the JPEG File Interchange Format v1.02 document by Eric Hamilton.
/// </summary>
/// <remarks>
/// The JPEG File Interchange Format is the de facto standard JPEG interchange format.
/// </remarks>
struct JfifParameters
{
    /// <summary>
    /// Version of the JPEG File Interchange Format.
    /// Should be set to zero to not write a JFIF header or to 1.02, encoded as: (1 * 256) + 2.
    /// </summary>
    int32_t version;

    /// <summary>
    /// Defines the units for the X and Y densities.
    /// 0: no units, X and Y specify the pixel aspect ratio.
    /// 1: X and Y are dots per inch.
    /// 2: X and Y are dots per cm.
    /// </summary>
    int32_t units;

    /// <summary>
    /// Horizontal pixel density
    /// </summary>
    int32_t Xdensity;

    /// <summary>
    /// Vertical pixel density
    /// </summary>
    int32_t Ydensity;

    /// <summary>
    /// Thumbnail horizontal pixel count.
    /// </summary>
    int32_t Xthumbnail;

    /// <summary>
    /// Thumbnail vertical pixel count.
    /// </summary>
    int32_t Ythumbnail;

    /// <summary>
    /// Reference to a buffer with thumbnail pixels of size Xthumbnail * Ythumbnail * 3(RGB).
    /// This parameter is only used when creating JPEG-LS encoded images.
    /// </summary>
    void* thumbnail;
};


struct JlsParameters
{
    /// <summary>
    /// Width of the image in pixels.
    /// </summary>
    int width;

    /// <summary>
    /// Height of the image in pixels.
    /// </summary>
    int height;

    /// <summary>
    /// The number of valid bits per sample to encode.
    /// Valid range 2 - 16. When greater than 8, pixels are assumed to stored as two bytes per sample, otherwise one byte per sample is assumed.
    /// </summary>
    int bitsPerSample;

    /// <summary>
    /// The stride is the number of bytes from one row of pixels in memory to the next row of pixels in memory.
    /// Stride is sometimes called pitch. If padding bytes are present, the stride is wider than the width of the image.
    /// </summary>
    int stride;

    /// <summary>
    /// The number of components.
    /// Typical 1 for monochrome images and 3 for color images or 4 if alpha channel is present.
    /// </summary>
    int components;

    /// <summary>
    /// Defines the allowed lossy error. Value 0 defines lossless.
    /// </summary>
    int allowedLossyError;

    /// <summary>
    /// Determines the order of the color components in the compressed stream.
    /// </summary>
    CharlsInterleaveModeType interleaveMode;

    /// <summary>
    /// Color transformation used in the compressed stream. The color transformations are all lossless and
    /// are an HP proprietary extension of the standard. Do not use the color transformations unless
    /// you know the decoder is capable of decoding it. Color transform typically improve compression ratios only
    /// for synthetic images (non - photo-realistic computer generated images).
    /// </summary>
    CharlsColorTransformationType colorTransformation;

    /// <summary>
    /// If set to true RGB images will be decoded to BGR. BGR is the standard ordering in MS Windows bitmaps.
    /// </summary>
    char outputBgr;

    struct JpegLSPresetCodingParameters custom;
    struct JfifParameters jfif;
};


#ifdef __cplusplus

#include <iostream>


//
// ByteStreamInfo & FromByteArray helper function
//
// ByteStreamInfo describes the stream: either set rawStream to a valid stream, or rawData/count, not both.
// it's possible to decode to memory streams, but using rawData will always be faster.
struct ByteStreamInfo
{
    std::basic_streambuf<char>* rawStream;
    uint8_t* rawData;
    std::size_t count;
};


inline ByteStreamInfo FromByteArray(void* bytes, std::size_t count) noexcept
{
    return { nullptr, static_cast<uint8_t*>(bytes), count };
}


inline ByteStreamInfo FromByteArrayConst(const void* bytes, std::size_t count) noexcept
{
    return FromByteArray(const_cast<void*>(bytes), count);
}


#endif

#endif
