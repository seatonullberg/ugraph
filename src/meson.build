cc = meson.get_compiler('c')
calg = cc.find_library('calg')
sources = files(['ugraph.c'])
library(
    'ugraph',
    sources,
    include_directories: inc,
    dependencies: calg,
    install: true,
)