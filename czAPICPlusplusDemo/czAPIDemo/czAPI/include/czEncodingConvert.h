#pragma once
#ifdef _MSC_VER
#define ENCODE_API __declspec(dllimport)
#elif __GNUC__
#define ENCODE_API
#endif

#define CZ_ENCODING_GB2312  0
#define CZ_ENCODING_UNICODE 1
#define CZ_ENCODING_UTF8    2

#ifdef __cplusplus
extern "C" {
#endif

ENCODE_API unsigned int code_unicode_to_gb2312(unsigned int code);

ENCODE_API unsigned int code_gb2312_to_unicode(unsigned int code);

ENCODE_API unsigned int code_convert(unsigned int code, int srcencoding, int dstencoding);

#ifdef __cplusplus
}
#endif