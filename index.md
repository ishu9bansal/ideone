## Welcome

Some usefull pieces of code, with problem statement and explanation of the solution. Also there is complexity analysis for the solutions. Some of the codes are usable in many kind of other problems. These can be used directly or indirectly to solve many problems.

# Explore
{% for page in site.pages %}
{% assign default_title = page.permalink | split: "_" | join: " " | capitalize %}
{% if page.publish %}
 - [{{ page.title | default: default_title }}]({{ page.permalink }})
{% endif %}
{% endfor %}

# Contribute
Want to contribute some code? Raise a pull request on this [repo](https://github.com/ishu9bansal/ideone)

Pick any of the [issues](https://github.com/ishu9bansal/ideone/issues) listed in the repo or add some new code.

If you have some suggestions or just want to chat :bowtie: [mail me](mailto:ishubansal1400@gmail.com)
