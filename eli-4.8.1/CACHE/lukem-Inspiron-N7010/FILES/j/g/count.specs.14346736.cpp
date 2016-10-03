# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/Eli/tests/wordcount/word.gla"



word:	$[A-Za-z]+	[CountWord]	{ Strings that are words }
	$[.:,;!?()/\"\'*-]		{ Strings that are punctuation }
