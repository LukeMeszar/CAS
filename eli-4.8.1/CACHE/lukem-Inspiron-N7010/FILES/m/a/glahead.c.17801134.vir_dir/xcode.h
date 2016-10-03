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

case 5:	/* Entered on:  A-Z a-z */
	St_19:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z a-z */
			goto St_31;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 21;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 6:	/* Entered on: 0-9 */
	St_13:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 4);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  E e */
		extcode = 18;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkint;
			goto St_26;}
		else if(c ==46) {		extcode = 18;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkint;
			goto St_25;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 18;
			mkint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 7:	/* Entered on: { */
	St_23:
			TokenEnd=p=auxPascalComment(TokenStart, p-TokenStart);
			extcode = 15001;
			goto done;

case 8:	/* Entered on: > */
	St_18:
		if((c= *p++) ==61) {			goto St_30;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 38;
			goto done;
			}

case 9:	/* Entered on: < */
	St_16:
		if((c= *p++) ==62) {			goto St_29;}
		else if(c ==61) {			goto St_28;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 36;
			goto done;
			}

case 10:	/* Entered on: : */
	St_14:
		if((c= *p++) ==61) {			goto St_27;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 5;
			goto done;
			}

case 11:	/* Entered on: . */
	St_11:
		if((c= *p++) ==46) {			goto St_24;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 30;
			goto done;
			}

case 12:	/* Entered on: ( */
	St_5:
		if((c= *p++) ==42) {			goto St_23;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 8;
			goto done;
			}

case 13:	/* Entered on: ' */
	St_4:
			TokenEnd=p=auxPascalString(TokenStart, p-TokenStart);
			extcode = 14;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;


default: TokenEnd=p; extcode=ExtCodeTbl[c]; goto done; /*  )-- / ; = [ ]-^ */
}
	St_24:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 40;
			goto done;
	St_27:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 49;
			goto done;
	St_28:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 34;
			goto done;
	St_29:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 35;
			goto done;
	St_30:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 37;
			goto done;
	St_25:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_32;}
		else {--p; goto fallback; }
	St_32:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 4);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  E e */
		extcode = 20;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_35;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 20;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_35:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_37;}
		else if( scanTbl[c+0] & 1<< 6){ /*  + - */
			goto St_36;}
		else {--p; goto fallback; }
	St_36:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_37;}
		else {--p; goto fallback; }
	St_37:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 4);--p;
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 20;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_26:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_34;}
		else if( scanTbl[c+0] & 1<< 6){ /*  + - */
			goto St_33;}
		else {--p; goto fallback; }
	St_33:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_34;}
		else {--p; goto fallback; }
	St_34:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 4);--p;
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 20;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_31:
		/*  0-9 A-Z a-z*/
		while(scanTbl[(c= *p++)+0] & 1<< 3);--p;
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 21;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
