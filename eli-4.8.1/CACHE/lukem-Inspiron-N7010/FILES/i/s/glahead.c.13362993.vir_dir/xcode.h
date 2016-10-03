switch (CaseTbl[c = *p++]) {
case 0:	/* sentinel - probably EOB */
  if (c == '\0') {
    p = TokenStart = TokenEnd = auxNUL(TokenStart, 0);
    if (*p) extcode = NORETURN;
    else {
      p = TokenStart = TokenEnd = auxEOF(TokenStart, 0);
      if (*p) extcode = NORETURN;
      else { extcode = EOFTOKEN; EndOfText(p, 0, &extcode, v); }
    }
    goto done;
  } else {
    obstack_grow(Csm_obstk, "char '", 6);
    obstack_cchgrow(Csm_obstk, c);
    message(
      ERROR,
      (char *)obstack_copy0(Csm_obstk, "' is not a token", 16),
      0,
      &curpos);
    TokenEnd = p;
    continue;
  }
  
case 1:	/* space */
  while (scanTbl[c = *p++] & 1<<0) ;
  TokenEnd = p - 1;
  continue;
case 2:	/* tab */
  do { StartLine -= TABSIZE(p - StartLine); }
  while (scanTbl[c = *p++] & 1<<1);
  TokenEnd = p - 1;
  continue;
case 4:	/* carriage return */
  if (*p == '\n') { TokenEnd = p; continue; }
case 3:	/* newline */
  do { LineNum++; } while (scanTbl[c = *p++] & 1<<2);
  StartLine = (TokenEnd = p - 1) - 1;
  continue;

case 5:	/* Entered on:  A-B D-Z _ a-z */
	St_13:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z */
			goto St_18;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 6;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 6:	/* Entered on: 0-9 */
	St_10:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 4);--p;
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 12;
			mkint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;

case 7:	/* Entered on: C */
	St_14:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 A-N P-Z _ a-z */
			goto St_18;}
		else if(c ==79) {			goto St_19;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 6;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 8:	/* Entered on: : */
	St_11:
		if((c= *p++) ==58) {			goto St_17;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 4;
			goto done;
			}

case 9:	/* Entered on: / */
	St_9:
		if((c= *p++) ==42) {			goto St_16;}
		else {TokenEnd=TokenStart;--p; goto fallback; }

case 10:	/* Entered on: # */
	St_5:
			TokenEnd=p=auxEOL(TokenStart, p-TokenStart);
			extcode = 15001;
			goto done;

case 11:	/* Entered on: " */
	St_4:
		if( scanTbl[(c= *p++)+0] & 1<< 6){ /*    1.-! #-255. */

		TokenEnd = TokenStart; /* prepare for error fallback */
			goto St_15;}
		else {TokenEnd=TokenStart;--p; goto fallback; }


default: TokenEnd=p; extcode=ExtCodeTbl[c]; goto done; /*  (-) , ; */
}
	St_15:
		/*    1.-! #-255.*/
		while(scanTbl[(c= *p++)+0] & 1<< 6);--p;
		if((c= *p++) ==34) {			goto St_20;}
		else {--p; goto fallback; }
	St_20:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 3;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_16:
			TokenEnd=p=auxCComment(TokenStart, p-TokenStart);
			extcode = 15001;
			goto done;
	St_17:
		if((c= *p++) ==61) {			goto St_21;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 7;
			goto done;
			}
	St_21:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 8;
			goto done;
	St_19:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  0-9 A-R T-Z _ a-z */
			goto St_18;}
		else if(c ==83) {			goto St_22;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 6;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_22:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  0-9 A-S U-Z _ a-z */
			goto St_18;}
		else if(c ==84) {			goto St_23;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 6;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_23:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z */
			goto St_18;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			goto done;
			}
	St_18:
		/*  0-9 A-Z _ a-z*/
		while(scanTbl[(c= *p++)+0] & 1<< 3);--p;
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 6;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
