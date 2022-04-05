/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CONC_H_RPCGEN
#define _CONC_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct strpair {
	char a[50];
	char b[50];
};
typedef struct strpair strpair;

struct str {
	char ans[100];
};
typedef struct str str;

#define ARR_PROG 0x4562877
#define VERSION1 1

#if defined(__STDC__) || defined(__cplusplus)
#define conc 1
extern  str * conc_1(strpair *, CLIENT *);
extern  str * conc_1_svc(strpair *, struct svc_req *);
extern int arr_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define conc 1
extern  str * conc_1();
extern  str * conc_1_svc();
extern int arr_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_strpair (XDR *, strpair*);
extern  bool_t xdr_str (XDR *, str*);

#else /* K&R C */
extern bool_t xdr_strpair ();
extern bool_t xdr_str ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CONC_H_RPCGEN */