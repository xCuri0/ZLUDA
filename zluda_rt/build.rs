use vergen::{Config, vergen};

fn main() {
  vergen(Config::default()).unwrap();

  cc::Build::new()
  .cpp(true)
  .include("../hiprt-sys/include/")
  .file("src/buildTraceKernel.cpp")
  .compile("buildTraceKernel.a");
}