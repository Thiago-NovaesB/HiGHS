push!(LOAD_PATH,"src/")

using Pkg;

Pkg.instantiate()

using Documenter, HighsDocs

# makedocs(sitename="HiGHS Documentation",format = Documenter.HTML(
# ))


makedocs(
    format = Documenter.HTML(
        # Use clean URLs, unless built as a "local" build
        # prettyurls = !("local" in ARGS),
        prettyurls = get(ENV, "CI", nothing) == "true",
        highlights = ["yaml"],
    ),
    clean = false,
    sitename = "HiGHS Documentation",
    authors = "Julian Hall, Ivet Galabova and Michael Feldmeier.",
    pages = [
        "Home" => "index.md",
        "About" => "about.md", 
        "Get Started" => "get-started.md",
        "Running the executable" => "run-executable.md",
        "Using HiGHS" => Any[
            "Model operations" => "man/guide.md",
            "Examples" => "man/examples.md"],
        "Options" => "man/options.md",
        "Linking" => "man/link.md",
        "Interfaces" => "man/interfaces.md",
        "Python Notebook" => "mini_example.html"
    ],
    strict = !("strict=false" in ARGS),
    doctest = ("doctest=only" in ARGS) ? :only : true,
)