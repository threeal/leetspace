import os


def generate_test_src(out_dir: str, config: any):
    with open(os.path.join(out_dir, "test.cpp"), "w") as output:
        output.write("#include <catch2/catch_test_macros.hpp>\n")
        output.write("#include <string>\n")
        output.write("#include <vector>\n")

        output.write("\n")
        for lang in config["solutions"]:
            output.write("%s solution_%s(" % (config["types"]["output"], lang))
            output.write(
                ", ".join(
                    [("%s %s" % (t, v)) for v, t in config["types"]["inputs"].items()]
                )
            )
            output.write(");\n")

        output.write("\nstruct TestCase {\n")
        output.write("  struct Inputs {\n")
        for v, t in config["types"]["inputs"].items():
            output.write("    %s %s;\n" % (t, v))
        output.write("  };\n\n")
        output.write("  std::string name;\n")
        output.write("  Inputs inputs;\n")
        output.write("  %s output;\n" % config["types"]["output"])
        output.write("};\n")

        def dump(data):
            import json

            string = json.dumps(data)

            # Replace square brackets with curly brackets.
            formatted_string = ""
            quotations = 0
            for c in string:
                if c == '"':
                    quotations += 1
                elif quotations % 2 == 0:
                    if c == "[":
                        formatted_string += "{"
                        continue
                    elif c == "]":
                        formatted_string += "}"
                        continue

                formatted_string += c

            return formatted_string

        output.write("\nconst std::vector<TestCase> test_cases = {\n")
        for name in config["test_cases"]:
            cfg = config["test_cases"][name]
            output.write("  {\n")
            output.write('    .name = "%s",\n' % name)
            output.write("    .inputs = {\n")
            for var, val in cfg["inputs"].items():
                output.write("      .%s = %s,\n" % (var, dump(val)))
            output.write("    },\n")
            output.write("    .output = %s\n" % dump(cfg["output"]))
            output.write("  },\n")
        output.write("};\n")

        for lang in config["solutions"]:
            output.write('\nTEST_CASE("%s (%s)") {\n' % (config["name"], lang))
            output.write("  for (const auto& [name, inputs, output] : test_cases) {\n")

            inputs = ", ".join(config["types"]["inputs"])
            output.write("    const auto [%s] = inputs;\n" % inputs)
            output.write("    CAPTURE(name, %s);\n" % inputs)
            output.write("    CHECK(solution_%s(%s) == output);\n" % (lang, inputs))

            output.write("  }\n")
            output.write("}\n")
