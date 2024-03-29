/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "scan.h"

bool_t
xdr_Input_file (XDR *xdrs, Input_file *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->fileName, 50))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_Input_dir (XDR *xdrs, Input_dir *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->dirName, 50))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->threshold))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_Stat (XDR *xdrs, Stat *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->chars))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->words))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->rows))
		 return FALSE;
	return TRUE;
}
