project('clog', 'c', version: '1.0.0')

project_url = ''
project_url_issues = project_url + '/issues/new'

conf = configuration_data()

warnings = []

################################################################################
# Project info

prettyname = 'CLOG'
full_name  = 'C Logger'

# General version
clog_version = meson.project_version()
compiler = meson.get_compiler('c')
common_cflags = compiler.get_supported_arguments([
	'-pedantic',
	'-Wfloat-equal',
	'-Wshadow',
	'-Wpointer-arith',
	'-Winit-self',
	'-Wno-unused-function',
	'-Wno-unused-parameter',
	'-Wno-unreachable-code',
	'-Wstrict-prototypes',
])

gtk4_minver       = '4.18.4'
gtk4              = dependency('gtk4',           version: '>='+gtk4_minver)

rootInclude = include_directories('.')
appInclude  = include_directories('src')
subdir('src')
subdir('tests')
