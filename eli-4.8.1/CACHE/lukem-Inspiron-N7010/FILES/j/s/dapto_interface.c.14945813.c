#ifdef MONITOR
extern void _dap_dapto_init ();
extern void _dap_csm_init ();
extern void _dap_err_init ();
extern void _dap_clp_init ();
extern void _dap_gla_init ();
extern void _dap_pdl_init ();
void _dap_interface_init () {
_dap_dapto_init ();
_dap_csm_init ();
_dap_err_init ();
_dap_clp_init ();
_dap_gla_init ();
_dap_pdl_init ();
}
#endif
