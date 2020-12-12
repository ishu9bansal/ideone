---
publish: true
permalink: fenwick_tree
title: Fenwick Tree
code:
  - dIYSUb
  - PdaqdH
usage:
  - https://leetcode.com/problems/count-of-smaller-numbers-after-self/
  - https://leetcode.com/submissions/detail/350260092/
  - https://leetcode.com/submissions/detail/350897497/
  - https://leetcode.com/submissions/detail/389860976/

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
