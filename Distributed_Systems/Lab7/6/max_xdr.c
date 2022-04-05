/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "max.h"

bool_t
xdr_numbers (XDR *xdrs, numbers *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, (1 +  20 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->size))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->a, 20,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->size);
			{
				register int *genp;

				for (i = 0, genp = objp->a;
					i < 20; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, (1 +  20 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->size))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->a, 20,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			objp->size = IXDR_GET_LONG(buf);
			{
				register int *genp;

				for (i = 0, genp = objp->a;
					i < 20; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->size))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->a, 20,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_ret (XDR *xdrs, ret *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->maxno))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->minno))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->avgno))
		 return FALSE;
	return TRUE;
}
