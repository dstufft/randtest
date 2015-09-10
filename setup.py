import setuptools

setuptools.setup(
    ext_modules=[
        setuptools.Extension(
            "_arc4random",
            sources=["_arc4random.c"],
        ),
    ],
)
