#include <mruby.h>
#include <pledge.h>
#include <sys/pledge.h>

static mrb_value
mrb_pledge(mrb_state *mrb, mrb_value self)
{
  const char *pledges;
  mrb_get_args(mrb, "z", &pledges);
  pledge_string(pledges);
}

void
mrb_mruby_hardened_pledge_gem_init(mrb_state* mrb) {
  mrb_define_method(mrb, mrb->kernel_module, "pledge", mrb_pledge, MRB_ARGS_REQ(1));
}

void
mrb_mruby_hardened_pledge_gem_final(mrb_state* mrb) {
  (void)mrb;
}