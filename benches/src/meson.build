bench_sources = files(['main.c', 'ugraph.c'])

m_dep = cc.find_library('m', required : false)

benchmark(
    'bench-ugraph',
    executable(
        'bench-ugraph',
        sources,
        bench_sources,
        dependencies: [calg_dep, m_dep],
        include_directories: [inc, bench_inc],
    )
)