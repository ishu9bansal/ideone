---
publish: true
permalink: binary_search
title: Binary Search
code:
  - pJwIFt
  - B0w11Y
usage:
  - https://leetcode.com/submissions/detail/417413492/

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
