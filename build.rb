MRuby::Build.new("mruby-hardened-pledge") do |conf|
  conf.toolchain
  conf.gem "."
end