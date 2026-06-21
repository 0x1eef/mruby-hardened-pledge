#include <mruby.h>
#include <pledge.h>
#include <sys/pledge.h>

static mrb_value
mrb_pledge(mrb_state *mrb, mrb_value self)
{
  const char *pledges, *execpledges;
  mrb_get_args(mrb, "zz", &pledges, &execpledges);
  pledge_string(pledges, execpledges);
  return mrb_nil_value();
}

void
mrb_mruby_hardened_pledge_gem_init(mrb_state* mrb) {
  mrb_define_method(mrb, mrb->kernel_module, "pledge", mrb_pledge, MRB_ARGS_REQ(2));
}

void
mrb_mruby_hardened_pledge_gem_final(mrb_state* mrb) {
  (void)mrb;
}