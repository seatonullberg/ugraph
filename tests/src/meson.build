test_sources = files(['main.c', 'ugraph.c'])
test(
    'test-ugraph',
    executable(
        'test-ugraph',
        sources,
        test_sources,
        dependencies: calg_dep,
        include_directories: [inc, test_inc],
    )
)