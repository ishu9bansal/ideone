---
publish: true
permalink: arbitrary_deep_recursive_output
code:
  - I9WNY7
usage:
  - https://leetcode.com/submissions/detail/361593754/

---
{% include_relative README.md %}
# Code

{% for x in page.code %}
```cpp
{% include_relative {{ x }}.cpp %}
```
# [Ideone it!](https://ideone.com/{{ x }})
{% endfor %}

{% for x in page.usage %}
{% if forloop.first %}
# Usage
{% endif %}
 - [Usage {{ forloop.index }}]({{x}})
{% endfor %}
