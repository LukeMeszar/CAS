# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/PKGS/dapto/dapto.dapto"






















aspect dapto;

event init* "Subject initialization"
 	(int pid "Process id of subject");
event finit* "Subject finalization" ();
event exit "Subject exit" ();

event stopped "Execution of the subject has stopped"
	(str locale "Place at which execution stopped",
	 int error "Whether this stoppage is due to a system error or not");










event enter "Enter a program component"
	(str name "Name of component");
event leave "Leave a program component"
	(str name "Name of component");

end;
