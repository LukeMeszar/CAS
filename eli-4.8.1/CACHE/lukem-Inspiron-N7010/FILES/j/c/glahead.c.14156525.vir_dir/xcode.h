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

case 5:	/* Entered on:  A-Z _ a-z */
	St_11:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z */
			goto St_19;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 3;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 6:	/* Entered on: 1-9 */
	St_10:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 4);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  E e */
		extcode = 2;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = c_mkint;
			goto St_17;}
		else if(c ==46) {			goto St_16;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 2;
			c_mkint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 7:	/* Entered on: 0 */
	St_9:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_10;}
		else if( scanTbl[c+0] & 1<< 6){ /*  X x */
			goto St_18;}
		else if( scanTbl[c+0] & 1<< 5){ /*  E e */
		extcode = 2;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = c_mkint;
			goto St_17;}
		else if(c ==46) {			goto St_16;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 2;
			c_mkint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 8:	/* Entered on: / */
	St_8:
		if((c= *p++) ==42) {			goto St_15;}
		else {TokenEnd=TokenStart;--p; goto fallback; }

case 9:	/* Entered on: . */
	St_7:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_14;}
		else {TokenEnd=TokenStart;--p; goto fallback; }

case 10:	/* Entered on: ' */
	St_6:
			TokenEnd=p=auxCChar(TokenStart, p-TokenStart);
			extcode = 6;
			c_mkchar(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;

case 11:	/* Entered on: # */
	St_5:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  A-Z a-z */
			goto St_13;}
		else if(c ==32) {
		TokenEnd = TokenStart; /* prepare for error fallback */
			goto St_12;}
		else {TokenEnd=TokenStart;--p; goto fallback; }

case 12:	/* Entered on: " */
	St_4:
			TokenEnd=p=auxCString(TokenStart, p-TokenStart);
			extcode = 5;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;


default: TokenEnd=p; extcode=ExtCodeTbl[c]; goto done; /*  */
}
	St_12:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  A-Z a-z */
			goto St_13;}
		else if( scanTbl[c+0] & 1<< 4){ /*  0-9 */
			goto St_21;}
		else if(c ==32) {			goto St_20;}
		else {--p; goto fallback; }
	St_20:
		/*   */
		while(scanTbl[(c= *p++)+0] & 1<< 0);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  A-Z a-z */
			goto St_13;}
		else {--p; goto fallback; }
	St_13:
			TokenEnd=p=auxEOL(TokenStart, p-TokenStart);
			extcode = 15001;
			goto done;
	St_21:
			TokenEnd=p=auxEOL(TokenStart, p-TokenStart);
			extcode = 15001;
			goto done;
	St_14:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 4);--p;
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  F L f l */
			goto St_23;}
		else if( scanTbl[c+0] & 1<< 5){ /*  E e */
		extcode = 7;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_22;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 7;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_22:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_29;}
		else if( scanTbl[c+256] & 1<< 1){ /*  + - */
			goto St_28;}
		else {--p; goto fallback; }
	St_28:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_29;}
		else {--p; goto fallback; }
	St_29:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 4);--p;
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  F L f l */
			goto St_23;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 7;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_23:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 7;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_15:
			TokenEnd=p=auxCComment(TokenStart, p-TokenStart);
			extcode = 15001;
			goto done;
	St_16:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_24;}
		else if( scanTbl[c+256] & 1<< 0){ /*  F L f l */
			goto St_23;}
		else if( scanTbl[c+0] & 1<< 5){ /*  E e */
		extcode = 7;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_22;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 7;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_24:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 4);--p;
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  F L f l */
			goto St_23;}
		else if( scanTbl[c+0] & 1<< 5){ /*  E e */
		extcode = 7;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_22;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 7;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_17:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_26;}
		else if( scanTbl[c+256] & 1<< 1){ /*  + - */
			goto St_25;}
		else {--p; goto fallback; }
	St_25:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_26;}
		else {--p; goto fallback; }
	St_26:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 4);--p;
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  F L f l */
			goto St_23;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 7;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_18:
		if( scanTbl[(c= *p++)+256] & 1<< 2){ /*  0-9 A-F a-f */
			goto St_27;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 2;
			c_mkint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_27:
		/*  0-9 A-F a-f*/
		while(scanTbl[(c= *p++)+256] & 1<< 2);--p;
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 2;
			c_mkint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_19:
		/*  0-9 A-Z _ a-z*/
		while(scanTbl[(c= *p++)+0] & 1<< 3);--p;
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 3;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
