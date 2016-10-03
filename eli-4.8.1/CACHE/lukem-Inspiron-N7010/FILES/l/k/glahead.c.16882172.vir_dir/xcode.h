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

case 5:	/* Entered on:  A-Z _ a d g-h j-q s-v x-z */
	St_23:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z */
			goto St_41;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 6:	/* Entered on: 1-9 */
	St_16:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 4);--p;
		if( scanTbl[(c= *p++)+0] & 1<< 5){ /*  E e */
		extcode = 23;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = c_mkint;
			goto St_38;}
		else if(c ==46) {			goto St_37;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 23;
			c_mkint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 7:	/* Entered on: | */
	St_32:
		if((c= *p++) ==124) {			goto St_50;}
		else {TokenEnd=TokenStart;--p; goto fallback; }

case 8:	/* Entered on: w */
	St_30:
		if( scanTbl[(c= *p++)+0] & 1<< 6){ /*  0-9 A-Z _ a-g i-z */
			goto St_41;}
		else if(c ==104) {			goto St_49;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 9:	/* Entered on: r */
	St_29:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  0-9 A-Z _ a-d f-z */
			goto St_41;}
		else if(c ==101) {			goto St_48;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 10:	/* Entered on: i */
	St_28:
		if( scanTbl[(c= *p++)+256] & 1<< 0){ /*  0-9 A-Z _ a-e g-m o-z */
			goto St_41;}
		else if(c ==110) {			goto St_47;}
		else if(c ==102) {			goto St_46;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 11:	/* Entered on: f */
	St_27:
		if( scanTbl[(c= *p++)+256] & 1<< 1){ /*  0-9 A-Z _ a-k m-z */
			goto St_41;}
		else if(c ==108) {			goto St_45;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 12:	/* Entered on: e */
	St_26:
		if( scanTbl[(c= *p++)+256] & 1<< 1){ /*  0-9 A-Z _ a-k m-z */
			goto St_41;}
		else if(c ==108) {			goto St_44;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 13:	/* Entered on: c */
	St_25:
		if( scanTbl[(c= *p++)+256] & 1<< 2){ /*  0-9 A-Z _ a-n p-z */
			goto St_41;}
		else if(c ==111) {			goto St_43;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 14:	/* Entered on: b */
	St_24:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  0-9 A-Z _ a-q s-z */
			goto St_41;}
		else if(c ==114) {			goto St_42;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 15:	/* Entered on: = */
	St_20:
		if((c= *p++) ==61) {			goto St_40;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 11;
			goto done;
			}

case 16:	/* Entered on: 0 */
	St_15:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_16;}
		else if( scanTbl[c+256] & 1<< 4){ /*  X x */
			goto St_39;}
		else if( scanTbl[c+0] & 1<< 5){ /*  E e */
		extcode = 23;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = c_mkint;
			goto St_38;}
		else if(c ==46) {			goto St_37;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 23;
			c_mkint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}

case 17:	/* Entered on: / */
	St_14:
		if((c= *p++) ==42) {			goto St_36;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 13;
			goto done;
			}

case 18:	/* Entered on: . */
	St_13:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_35;}
		else {TokenEnd=TokenStart;--p; goto fallback; }

case 19:	/* Entered on: & */
	St_6:
		if((c= *p++) ==38) {			goto St_34;}
		else {TokenEnd=TokenStart;--p; goto fallback; }


default: TokenEnd=p; extcode=ExtCodeTbl[c]; goto done; /*  ! % (-- :-< >-? { } */
}
	St_34:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 4;
			goto done;
	St_35:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 4);--p;
		if( scanTbl[(c= *p++)+256] & 1<< 5){ /*  F L f l */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  E e */
		extcode = 22;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_51;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 22;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_51:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_65;}
		else if( scanTbl[c+256] & 1<< 6){ /*  + - */
			goto St_64;}
		else {--p; goto fallback; }
	St_64:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_65;}
		else {--p; goto fallback; }
	St_65:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 4);--p;
		if( scanTbl[(c= *p++)+256] & 1<< 5){ /*  F L f l */
			goto St_52;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 22;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_52:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 22;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_36:
			TokenEnd=p=auxCComment(TokenStart, p-TokenStart);
			extcode = 15001;
			goto done;
	St_37:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_53;}
		else if( scanTbl[c+256] & 1<< 5){ /*  F L f l */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  E e */
		extcode = 22;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_51;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 22;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_53:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 4);--p;
		if( scanTbl[(c= *p++)+256] & 1<< 5){ /*  F L f l */
			goto St_52;}
		else if( scanTbl[c+0] & 1<< 5){ /*  E e */
		extcode = 22;/* remember fallback*/
		TokenEnd = p-1;

		scan = NULL;
		proc = mkstr;
			goto St_51;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 22;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_38:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_55;}
		else if( scanTbl[c+256] & 1<< 6){ /*  + - */
			goto St_54;}
		else {--p; goto fallback; }
	St_54:
		if( scanTbl[(c= *p++)+0] & 1<< 4){ /*  0-9 */
			goto St_55;}
		else {--p; goto fallback; }
	St_55:
		/*  0-9*/
		while(scanTbl[(c= *p++)+0] & 1<< 4);--p;
		if( scanTbl[(c= *p++)+256] & 1<< 5){ /*  F L f l */
			goto St_52;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 22;
			mkstr(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_39:
		if( scanTbl[(c= *p++)+256] & 1<< 7){ /*  0-9 A-F a-f */
			goto St_56;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 23;
			c_mkint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_56:
		/*  0-9 A-F a-f*/
		while(scanTbl[(c= *p++)+256] & 1<< 7);--p;
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 23;
			c_mkint(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_40:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 10;
			goto done;
	St_42:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  0-9 A-Z _ a-d f-z */
			goto St_41;}
		else if(c ==101) {			goto St_57;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_57:
		if( scanTbl[(c= *p++)+512] & 1<< 0){ /*  0-9 A-Z _ b-z */
			goto St_41;}
		else if(c ==97) {			goto St_66;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_66:
		if( scanTbl[(c= *p++)+512] & 1<< 1){ /*  0-9 A-Z _ a-j l-z */
			goto St_41;}
		else if(c ==107) {			goto St_72;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_72:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z */
			goto St_41;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 27;
			goto done;
			}
	St_41:
		/*  0-9 A-Z _ a-z*/
		while(scanTbl[(c= *p++)+0] & 1<< 3);--p;
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
	St_43:
		if( scanTbl[(c= *p++)+512] & 1<< 2){ /*  0-9 A-Z _ a-m o-z */
			goto St_41;}
		else if(c ==110) {			goto St_58;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_58:
		if( scanTbl[(c= *p++)+512] & 1<< 3){ /*  0-9 A-Z _ a-s u-z */
			goto St_41;}
		else if(c ==116) {			goto St_67;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_67:
		if( scanTbl[(c= *p++)+512] & 1<< 4){ /*  0-9 A-Z _ a-h j-z */
			goto St_41;}
		else if(c ==105) {			goto St_73;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_73:
		if( scanTbl[(c= *p++)+512] & 1<< 2){ /*  0-9 A-Z _ a-m o-z */
			goto St_41;}
		else if(c ==110) {			goto St_77;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_77:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-t v-z */
			goto St_41;}
		else if(c ==117) {			goto St_79;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_79:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  0-9 A-Z _ a-d f-z */
			goto St_41;}
		else if(c ==101) {			goto St_80;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_80:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z */
			goto St_41;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 28;
			goto done;
			}
	St_44:
		if( scanTbl[(c= *p++)+512] & 1<< 6){ /*  0-9 A-Z _ a-r t-z */
			goto St_41;}
		else if(c ==115) {			goto St_59;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_59:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  0-9 A-Z _ a-d f-z */
			goto St_41;}
		else if(c ==101) {			goto St_68;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_68:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z */
			goto St_41;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 30;
			goto done;
			}
	St_45:
		if( scanTbl[(c= *p++)+256] & 1<< 2){ /*  0-9 A-Z _ a-n p-z */
			goto St_41;}
		else if(c ==111) {			goto St_60;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_60:
		if( scanTbl[(c= *p++)+512] & 1<< 0){ /*  0-9 A-Z _ b-z */
			goto St_41;}
		else if(c ==97) {			goto St_69;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_69:
		if( scanTbl[(c= *p++)+512] & 1<< 3){ /*  0-9 A-Z _ a-s u-z */
			goto St_41;}
		else if(c ==116) {			goto St_74;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_74:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z */
			goto St_41;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 17;
			goto done;
			}
	St_46:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z */
			goto St_41;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 29;
			goto done;
			}
	St_47:
		if( scanTbl[(c= *p++)+512] & 1<< 3){ /*  0-9 A-Z _ a-s u-z */
			goto St_41;}
		else if(c ==116) {			goto St_61;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_61:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z */
			goto St_41;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 18;
			goto done;
			}
	St_48:
		if( scanTbl[(c= *p++)+512] & 1<< 3){ /*  0-9 A-Z _ a-s u-z */
			goto St_41;}
		else if(c ==116) {			goto St_62;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_62:
		if( scanTbl[(c= *p++)+512] & 1<< 5){ /*  0-9 A-Z _ a-t v-z */
			goto St_41;}
		else if(c ==117) {			goto St_70;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_70:
		if( scanTbl[(c= *p++)+256] & 1<< 3){ /*  0-9 A-Z _ a-q s-z */
			goto St_41;}
		else if(c ==114) {			goto St_75;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_75:
		if( scanTbl[(c= *p++)+512] & 1<< 2){ /*  0-9 A-Z _ a-m o-z */
			goto St_41;}
		else if(c ==110) {			goto St_78;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_78:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z */
			goto St_41;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 31;
			goto done;
			}
	St_49:
		if( scanTbl[(c= *p++)+512] & 1<< 4){ /*  0-9 A-Z _ a-h j-z */
			goto St_41;}
		else if(c ==105) {			goto St_63;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_63:
		if( scanTbl[(c= *p++)+256] & 1<< 1){ /*  0-9 A-Z _ a-k m-z */
			goto St_41;}
		else if(c ==108) {			goto St_71;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_71:
		if( scanTbl[(c= *p++)+0] & 1<< 7){ /*  0-9 A-Z _ a-d f-z */
			goto St_41;}
		else if(c ==101) {			goto St_76;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 12;
			mkidn(TokenStart, TokenEnd-TokenStart,&extcode,v);
			goto done;
			}
	St_76:
		if( scanTbl[(c= *p++)+0] & 1<< 3){ /*  0-9 A-Z _ a-z */
			goto St_41;}
		else {
			TokenEnd= (--p); /* FINAL, no auxscan, must set */
			extcode = 32;
			goto done;
			}
	St_50:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 5;
			goto done;
