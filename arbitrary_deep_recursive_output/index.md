---
permalink: arbitrary_deep_recursive_output
code: I9WNY7
usage:
  - https://leetcode.com/submissions/detail/361593754/

---
{% assign page.title = page.permalink.split("_").join(" ")capitalize() %}
{% include_relative README.md %}
# Code
```cpp
{% include_relative {{ page.code }}.cpp %}
```

# [Ideone it!](https://ideone.com/{{ page.code }})

{% for x in page.usage %}
{% if forloop.first %}
# Usage
{% endif %}
 - [Usage {{ forloop.index }}]({{x}})
{% endfor %}
