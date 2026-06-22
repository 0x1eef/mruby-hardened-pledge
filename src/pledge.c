#include <mruby.h>

#ifdef defined(__FreeBSD__)
#include <pledge.h>
#endif

#ifdef defined(__OpenBSD__)
#include <unistd.h>
#endif

static mrb_value
mrb_pledge(mrb_state *mrb, mrb_value self)
{
  const char *pledges, *execpledges;
  int error;
  mrb_get_args(mrb, "zz!", &pledges, &execpledges);

#ifdef defined(__FreeBSD__)
  if (execpledges == NULL)
    execpledges = "inherit";
  error = pledge_string(pledges, execpledges);
#endif

#ifdef defined(__OpenBSD__)
  error = pledge(pledges, execpledges);
#endif

  return mrb_fixnum_value(error);
}

void
mrb_mruby_hardened_pledge_gem_init(mrb_state* mrb) {
  mrb_define_method(mrb, mrb->kernel_module, "pledge", mrb_pledge, MRB_ARGS_REQ(2));
}

void
mrb_mruby_hardened_pledge_gem_final(mrb_state* mrb) {
  (void)mrb;
}