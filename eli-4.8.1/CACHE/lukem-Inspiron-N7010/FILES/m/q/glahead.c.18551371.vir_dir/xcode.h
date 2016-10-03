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

case 5:	/* Entered on: d */
	St_4:
		if((c= *p++) ==117) {
		TokenEnd = TokenStart; /* prepare for error fallback */
			goto St_5;}
		else {TokenEnd=TokenStart;--p; goto fallback; }


default: TokenEnd=p; extcode=ExtCodeTbl[c]; goto done; /*  */
}
	St_5:
		if((c= *p++) ==109) {			goto St_6;}
		else {--p; goto fallback; }
	St_6:
		if((c= *p++) ==109) {			goto St_7;}
		else {--p; goto fallback; }
	St_7:
		if((c= *p++) ==121) {			goto St_8;}
		else {--p; goto fallback; }
	St_8:
			TokenEnd= p; /* FINAL, no auxscan, must set */
			extcode = 2;
			goto done;
