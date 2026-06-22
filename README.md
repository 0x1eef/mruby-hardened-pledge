<p align="center">
<img width=400 height=250 src="4.4bsd.svg">
</p>

mruby-hardened-pledge provides mruby bindings for the
pledge feature that are available on both OpenBSD, and
HardenedBSD. The APIs are similar but the pledges can
differ.

## Quick start

#### OpenBSD

```ruby
##
# Equivalent to pledge("inet", NULL)
pledge("inet", nil)

##
# Crash
File.open("/etc/passwd", "r") { f.gets }
```

#### HardenedBSD

```ruby
##
# Equivalent to pledge_string("inet", "inherit")
pledge("inet", nil)

##
# Crash
File.open("/etc/passwd", "r") { f.gets }
```

## License

0BSD. <br>
See [LICENSE](./LICENSE)