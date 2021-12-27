// ----------------------------------------------------------------------------
// Generated by InterfaceFactory [Wed May 07 00:56:11 2003]
// 
// File        : api_service.h
// Class       : api_service
// class layer : Dispatchable Interface
// ----------------------------------------------------------------------------

#ifndef __API_SERVICE_H
#define __API_SERVICE_H

#include <bfc/dispatch.h>
#include <bfc/common.h>

class waServiceFactory;


// ----------------------------------------------------------------------------

class COMEXP api_service: public Dispatchable {
  protected:
    api_service() {}
    ~api_service() {}
  public:
    int service_register(waServiceFactory *svc);
    int service_deregister(waServiceFactory *svc);
    int service_getNumServices(FOURCC svc_type);
    waServiceFactory *service_enumService(FOURCC svc_type, int n);
    waServiceFactory *service_getServiceByGuid(GUID guid);
    int service_lock(waServiceFactory *owner, void *svcptr);
    int service_clientLock(void *svcptr);
    int service_release(void *svcptr);
    const char *service_getTypeName(FOURCC svc_type);
  #ifdef WASABI_COMPILE_COMPONENTS
    GUID service_getOwningComponent(void *svcptr);
    GUID service_getLockingComponent(void *svcptr);
  #endif // WASABI_COMPILE_COMPONENTS
    int service_unlock(void *svcptr);
    int service_isvalid(FOURCC svctype, waServiceFactory *service);
  
  protected:
    enum {
      API_SERVICE_SERVICE_REGISTER = 10,
      API_SERVICE_SERVICE_DEREGISTER = 20,
      API_SERVICE_SERVICE_GETNUMSERVICES = 30,
      API_SERVICE_SERVICE_ENUMSERVICE = 40,
      API_SERVICE_SERVICE_GETSERVICEBYGUID = 50,
      API_SERVICE_SERVICE_LOCK = 60,
      API_SERVICE_SERVICE_CLIENTLOCK = 70,
      API_SERVICE_SERVICE_RELEASE = 80,
      API_SERVICE_SERVICE_GETTYPENAME = 90,
      #ifdef WASABI_COMPILE_COMPONENTS
      API_SERVICE_SERVICE_GETOWNINGCOMPONENT = 100,
      API_SERVICE_SERVICE_GETLOCKINGCOMPONENT = 110,
      #endif // WASABI_COMPILE_COMPONENTS
      API_SERVICE_SERVICE_UNLOCK = 120,
      API_SERVICE_ISVALID = 130,
    };
};

// ----------------------------------------------------------------------------

inline int api_service::service_register(waServiceFactory *svc) {
  int __retval = _call(API_SERVICE_SERVICE_REGISTER, (int)0, svc);
  return __retval;
}

inline int api_service::service_deregister(waServiceFactory *svc) {
  int __retval = _call(API_SERVICE_SERVICE_DEREGISTER, (int)0, svc);
  return __retval;
}

inline int api_service::service_getNumServices(FOURCC svc_type) {
  int __retval = _call(API_SERVICE_SERVICE_GETNUMSERVICES, (int)0, svc_type);
  return __retval;
}

inline waServiceFactory *api_service::service_enumService(FOURCC svc_type, int n) {
  waServiceFactory *__retval = _call(API_SERVICE_SERVICE_ENUMSERVICE, (waServiceFactory *)NULL, svc_type, n);
  return __retval;
}

inline waServiceFactory *api_service::service_getServiceByGuid(GUID guid) {
  waServiceFactory *__retval = _call(API_SERVICE_SERVICE_GETSERVICEBYGUID, (waServiceFactory *)NULL, guid);
  return __retval;
}

inline int api_service::service_lock(waServiceFactory *owner, void *svcptr) {
  int __retval = _call(API_SERVICE_SERVICE_LOCK, (int)0, owner, svcptr);
  return __retval;
}

inline int api_service::service_clientLock(void *svcptr) {
  int __retval = _call(API_SERVICE_SERVICE_CLIENTLOCK, (int)0, svcptr);
  return __retval;
}

inline int api_service::service_release(void *svcptr) {
  int __retval = _call(API_SERVICE_SERVICE_RELEASE, (int)0, svcptr);
  return __retval;
}

inline const char *api_service::service_getTypeName(FOURCC svc_type) {
  const char *__retval = _call(API_SERVICE_SERVICE_GETTYPENAME, (const char *)0, svc_type);
  return __retval;
}

#ifdef WASABI_COMPILE_COMPONENTS
inline GUID api_service::service_getOwningComponent(void *svcptr) {
  GUID __retval = _call(API_SERVICE_SERVICE_GETOWNINGCOMPONENT, INVALID_GUID, svcptr);
  return __retval;
}

inline GUID api_service::service_getLockingComponent(void *svcptr) {
  GUID __retval = _call(API_SERVICE_SERVICE_GETLOCKINGCOMPONENT, INVALID_GUID, svcptr);
  return __retval;
}

#endif // WASABI_COMPILE_COMPONENTS
inline int api_service::service_unlock(void *svcptr) {
  int __retval = _call(API_SERVICE_SERVICE_UNLOCK, (int)0, svcptr);
  return __retval;
}

inline int api_service::service_isvalid(FOURCC svctype, waServiceFactory *service) {
  int __retval = _call(API_SERVICE_ISVALID, (int)0, svctype, service);
  return __retval;
}

// ----------------------------------------------------------------------------


extern api_service *serviceApi;

#endif // __API_SERVICE_H