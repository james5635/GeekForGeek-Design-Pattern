# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

from sphinx.application import Sphinx


project = "Design Pattern"
copyright = "2026, Sou Chanrojame"
author = "Sou Chanrojame"

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = [
    # "sphinx_immaterial",
    # "sphinx_rtd_theme",
    "sphinx_copybutton",
]

latex_engine = "xelatex"

# templates_path = ["_templates"]
exclude_patterns = []


# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = "alabaster"
# html_theme_options = {
    # "body_max_width": "none",
    # "page_width": "auto",
# }
# html_static_path = ["_static"]
# html_css_files = ["custom/alabaster/mycustom.css"]
# pygments_style = "github-light"


# html_theme = "sphinxdoc"
# html_theme = "shibuya"

# html_theme = 'sphinx_immaterial'

# html_theme = "sphinx_rtd_theme"
# html_static_path = ["_static"]
# html_css_files = ["custom/rtd//custom.css"]
# html_js_files = ["custom/rtd/sidebar-toggle.js"]
# def setup(app):
#     app.add_js_file(
#         None,
#         body="""
#         (function() {
#             if (localStorage.getItem("sidebarHidden") === "true") {
#                 document.documentElement.classList.add("sidebar-hidden");
#             }
#         })();
#         """,
#     )
# pygments_style = "vs"
# latex_elements = {
#     # ... other elements ...
#     'sphinxsetup': r"""
#         VerbatimColor={RGB}{255,255,255},
#         VerbatimBorderColor={rgb}{0.648,0.165,0.165},
#     """,
# }
