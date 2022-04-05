/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rev.h"

bool_t
xdr_arr (XDR *xdrs, arr *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, (1 +  50 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->size))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->a, 50,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->size);
			{
				register int *genp;

				for (i = 0, genp = objp->a;
					i < 50; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, (1 +  50 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->size))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->a, 50,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			objp->size = IXDR_GET_LONG(buf);
			{
				register int *genp;

				for (i = 0, genp = objp->a;
					i < 50; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->size))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->a, 50,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}
