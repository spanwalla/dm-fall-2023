import pybind11
from distutils.core import setup, Extension

ext_modules = [
	Extension(
		'pybind11module',
		['module.cpp'],
		include_dirs=[pybind11.get_include()],
		language='c++',
		extra_compile_args=['-std=c++20'],
	),
]

setup(
	name='pybind11module',
	version='0.0.1',
	ext_modules=ext_modules,
	requires=['pybind11']
)
