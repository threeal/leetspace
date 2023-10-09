import yaml
import sys

with open(sys.argv[1], 'r') as config_file:
    config = yaml.safe_load(config_file)
    name = config["name"]

    headers = {
        "<catch2/catch_test_macros.hpp>",
        "<interface.hpp>",
        "<test_cases.hpp>",
        "<string>"
    }

    types = list(config["types"]["inputs"].values())
    types.append(config["types"]["output"])
    for t in types:
        if "std::vector" in t:
            headers.add("<vector>")

    with open(sys.argv[2], "w") as output:
        for header in headers:
            output.write("#include %s\n" % header)

        output.write("\nTEST_CASE(\"%s\") {\n" % name)
        output.write("  for (const auto& test_case : test_cases) {\n")

        variables = {"name": "std::string"}
        for v, t in config["types"]["inputs"].items():
            variables[v] = t
        variables["expected"] = config["types"]["output"]

        for v, t in variables.items():
            output.write("    const auto %s = test_case[\"%s\"].as<%s>();\n" % (v, v, t))

        inputs = ", ".join(config["types"]["inputs"])
        output.write("\n    CAPTURE(name, %s);\n" % inputs)
        for lang in config["solutions"]:
            output.write("    CHECK(solution_%s<%s>(%s) == expected);\n" % (lang, config["types"]["output"], inputs))


        output.write("  }\n")
        output.write("}\n")
