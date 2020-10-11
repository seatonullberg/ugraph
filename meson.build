project('ugraph', 'c', version: '1.0.0')
cc = meson.get_compiler('c')

calg_proj = subproject('calg')
calg_dep = calg_proj.get_variable('calg_dep')

subdir('include')
subdir('src')
subdir('tests')
subdir('benches')
