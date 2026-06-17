MRuby::Gem::Specification.new("mruby-hardened-pledge") do |spec|
  spec.license = "0BSD"
  spec.author  = "Robert <robert@4.4bsd.dev>"
  spec.summary = "mruby bindings for HardenedBSD's libpledge"
  spec.linker.libraries << "pledge"
end