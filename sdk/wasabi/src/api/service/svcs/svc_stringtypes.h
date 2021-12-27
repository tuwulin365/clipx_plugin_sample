#ifndef _SVC_STRINGTYPES_H
#define _SVC_STRINGTYPES_H

// Here, you look like you're in need of some error codes.
namespace SvcStrCnv {
  typedef enum {
    // The conversion failed for some generic 'fatal' reason, not covered by the
    // other reasons below.  (Possibly a bug in the service implementation).
    ERROR_FATAL = -1,

    // The conversion failed because your output buffer was too small.
    ERROR_BUFFER_OVERRUN = -2,

    // The conversion failed because your input string had unrecoverable errors in it
    ERROR_INPUT = -3,

    // The service instance does not support that type of encoding for conversion
    ERROR_INVALID = -4,

    // The service instance isn't available (ONLY generated by EncodedStr.cpp, obviously)
    ERROR_UNAVAILABLE = -5,

  } ConvertErrors;

  // These types MUST be supported by the platform port for this service.
  typedef enum {
    OSNATIVE=MK4CC('n','a','t','v'),
    UTF16=MK4CC('u','-','1','6'),
  } EncodingTypes;
  // Other service instances may implement other encoding types.
  // They all should provide their own FOURCC #define or enum in their headers.
}


#endif // _SVC_STRINGTYPES_H
