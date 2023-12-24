
#ifndef PLAYRHO_EXPORT_H
#define PLAYRHO_EXPORT_H

#ifdef PLAYRHO_STATIC_DEFINE
#  define PLAYRHO_EXPORT
#  define PLAYRHO_NO_EXPORT
#else
#  ifndef PLAYRHO_EXPORT
#    ifdef PlayRho_EXPORTS
        /* We are building this library */
#      define PLAYRHO_EXPORT 
#    else
        /* We are using this library */
#      define PLAYRHO_EXPORT 
#    endif
#  endif

#  ifndef PLAYRHO_NO_EXPORT
#    define PLAYRHO_NO_EXPORT 
#  endif
#endif

#ifndef PLAYRHO_DEPRECATED
#  define PLAYRHO_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef PLAYRHO_DEPRECATED_EXPORT
#  define PLAYRHO_DEPRECATED_EXPORT PLAYRHO_EXPORT PLAYRHO_DEPRECATED
#endif

#ifndef PLAYRHO_DEPRECATED_NO_EXPORT
#  define PLAYRHO_DEPRECATED_NO_EXPORT PLAYRHO_NO_EXPORT PLAYRHO_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef PLAYRHO_NO_DEPRECATED
#    define PLAYRHO_NO_DEPRECATED
#  endif
#endif

#endif /* PLAYRHO_EXPORT_H */
