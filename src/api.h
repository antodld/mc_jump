#pragma once

#if defined _WIN32 || defined __CYGWIN__
#  define JumpingController_DLLIMPORT __declspec(dllimport)
#  define JumpingController_DLLEXPORT __declspec(dllexport)
#  define JumpingController_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#    define JumpingController_DLLIMPORT __attribute__((visibility("default")))
#    define JumpingController_DLLEXPORT __attribute__((visibility("default")))
#    define JumpingController_DLLLOCAL __attribute__((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#    define JumpingController_DLLIMPORT
#    define JumpingController_DLLEXPORT
#    define JumpingController_DLLLOCAL
#  endif // __GNUC__ >= 4
#endif // defined _WIN32 || defined __CYGWIN__

#ifdef JumpingController_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define JumpingController_DLLAPI
#  define JumpingController_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef JumpingController_EXPORTS
#    define JumpingController_DLLAPI JumpingController_DLLEXPORT
#  else
#    define JumpingController_DLLAPI JumpingController_DLLIMPORT
#  endif // JumpingController_EXPORTS
#  define JumpingController_LOCAL JumpingController_DLLLOCAL
#endif // JumpingController_STATIC