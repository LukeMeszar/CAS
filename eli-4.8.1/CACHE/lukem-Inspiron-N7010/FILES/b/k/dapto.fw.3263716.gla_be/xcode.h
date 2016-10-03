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

case 5:	/* Entered on:  A-Z _ b-d f-n p-s u-z 192.-214. 216.-246. 248.-255. */
	St_14:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 6:	/* Entered on: { */
	St_19:
			TokenEnd=p=Ctext(TokenStart, p-TokenStart);
			extcode = 13;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;

case 7:	/* Entered on: t */
	St_18:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 A-Z _ a-q s-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==114) {			goto St_27;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 8:	/* Entered on: o */
	St_17:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 A-Z _ a-o q-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==112) {			goto St_26;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 9:	/* Entered on: e */
	St_16:
		if( scanTbl[(c= *p++)+0] & 1<< 6){ /*  0-9 A-Z _ a-m o-u w-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==118) {			goto St_25;}
		else if(c ==110) {			goto St_24;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 10:	/* Entered on: a */
	St_15:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  0-9 A-Z _ a-r t-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==115) {			goto St_23;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 11:	/* Entered on: < */
	St_13:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*    1.-= ?-255. */

		TokenEnd = TokenStart; /* prepare for error fallback */
			goto St_21;}
		else {TokenEnd=TokenStart;--p; goto fallback; }

case 12:	/* Entered on: / */
	St_10:
		if((c= *p++) ==42) {			goto St_20;}
		else {TokenEnd=TokenStart;--p; goto fallback; }

case 13:	/* Entered on: # */
	St_5:
			TokenEnd=p=auxEOL(TokenStart, p-TokenStart);
			extcode = 15001;
			goto done;

case 14:	/* Entered on: " */
	St_4:
			TokenEnd=p=auxCString(TokenStart, p-TokenStart);
			extcode = 6;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;


default: TokenEnd=p; extcode=ExtCodeTbl[c]; goto done; /*  (-* , :-; */
}
	St_20:
			TokenEnd=p=auxCComment(TokenStart, p-TokenStart);
			extcode = 15001;
			goto done;
	St_21:
		/*    1.-= ?-255.*/
		while(scanTbl[(c= *p++)+256] & 1<< 0);--p;
		if((c= *p++) ==62) {			goto St_28;}
		else {--p; goto fallback; }
	St_28:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 15;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_23:
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  0-9 A-Z _ a-o q-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==112) {			goto St_29;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_29:
		if( scanTbl[(c= *p++)+256] & 1<< 1){ /*  0-9 A-Z _ a-d f-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==101) {			goto St_34;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_34:
		if( scanTbl[(c= *p++)+256] & 1<< 2){ /*  0-9 A-Z _ a-b d-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==99) {			goto St_38;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_38:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  0-9 A-Z _ a-s u-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==116) {			goto St_42;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_42:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 2;
			goto done;
			}
	St_22:
		/*  0-9 A-Z _ a-z 192.-214. 216.-246. 248.-255.*/
		while(scanTbl[(c= *p++)+0] & 1<< 3);--p;
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_24:
		if( scanTbl[(c= *p++)+256] & 1<< 4){ /*  0-9 A-Z _ a-c e-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==100) {			goto St_30;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_30:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 4;
			goto done;
			}
	St_25:
		if( scanTbl[(c= *p++)+256] & 1<< 1){ /*  0-9 A-Z _ a-d f-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==101) {			goto St_31;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_31:
		if( scanTbl[(c= *p++)+256] & 1<< 5){ /*  0-9 A-Z _ a-m o-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==110) {			goto St_35;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_35:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  0-9 A-Z _ a-s u-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==116) {			goto St_39;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_39:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 9;
			goto done;
			}
	St_26:
		if( scanTbl[(c= *p++)+256] & 1<< 1){ /*  0-9 A-Z _ a-d f-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==101) {			goto St_32;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_32:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 A-Z _ a-q s-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==114) {			goto St_36;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_36:
		if( scanTbl[(c= *p++)+256] & 1<< 6){ /*  0-9 A-Z _ b-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==97) {			goto St_40;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_40:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  0-9 A-Z _ a-s u-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==116) {			goto St_43;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_43:
		if( scanTbl[(c= *p++)+256] & 1<< 7){ /*  0-9 A-Z _ a-h j-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==105) {			goto St_45;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_45:
		if( scanTbl[(c= *p++)+512] & 1<< 0){ /*  0-9 A-Z _ a-n p-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==111) {			goto St_47;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_47:
		if( scanTbl[(c= *p++)+256] & 1<< 5){ /*  0-9 A-Z _ a-m o-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==110) {			goto St_49;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_49:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			goto done;
			}
	St_27:
		if( scanTbl[(c= *p++)+256] & 1<< 6){ /*  0-9 A-Z _ b-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==97) {			goto St_33;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_33:
		if( scanTbl[(c= *p++)+256] & 1<< 5){ /*  0-9 A-Z _ a-m o-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==110) {			goto St_37;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_37:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  0-9 A-Z _ a-r t-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==115) {			goto St_41;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_41:
		if( scanTbl[(c= *p++)+512] & 1<< 1){ /*  0-9 A-Z _ a-k m-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==108) {			goto St_44;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_44:
		if( scanTbl[(c= *p++)+256] & 1<< 6){ /*  0-9 A-Z _ b-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==97) {			goto St_46;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_46:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  0-9 A-Z _ a-s u-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==116) {			goto St_48;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_48:
		if( scanTbl[(c= *p++)+256] & 1<< 7){ /*  0-9 A-Z _ a-h j-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==105) {			goto St_50;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_50:
		if( scanTbl[(c= *p++)+512] & 1<< 0){ /*  0-9 A-Z _ a-n p-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==111) {			goto St_51;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_51:
		if( scanTbl[(c= *p++)+256] & 1<< 5){ /*  0-9 A-Z _ a-m o-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else if(c ==110) {			goto St_52;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_52:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z 192.-214. 216.-246. 248.-255. */
			goto St_22;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 16;
			goto done;
			}
