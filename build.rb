MRuby::Build.new("mruby-hardened-pledge") do |conf|
  conf.toolchain
  conf.gem core: "mruby-compiler"
  conf.gem core: "mruby-bin-mrbc"
  conf.gem "."
end