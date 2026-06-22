MRuby::Gem::Specification.new("mruby-hardened-pledge") do |spec|
  spec.license = "0BSD"
  spec.author  = "Robert <robert@4.4bsd.dev>"
  spec.summary = "mruby bindings for (Open|Hardened)BSD's pledge feature"
  spec.linker.libraries << "pledge" unless ENV["NOLINK_PLEDGE"]
end