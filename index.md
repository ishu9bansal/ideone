## Welcome

Some usefull pieces of code, with problem statement and explanation of the solution. Also there is complexity analysis for the solutions. Some of the codes are usable in many kind of other problems. These can be used directly or indirectly to solve many problems.

# Pages
{% for page in site.pages %}
{% assign default_title = page.permalink | split: "_" | join: " " | capitalize %}
 - [{{ page.title | default: default_title }}]({{ page.permalink }})
{% endfor %}
