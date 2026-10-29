# Update the changelog
changelog version:
    clogs "{{ version }}"

# Create and push the release commit
commit version:
    git add .
    git commit -m "Release v{{ version }}"
    git push origin "$(git rev-parse --abbrev-ref HEAD)"

# Create the release tag
tag version:
    git tag -a -m "Release v{{ version }}" "v{{ version }}"
    git push origin "v{{ version }}"

# Update the version in several places
update-version version:
    sed -E -i -e 's/^VERSION := ([0-9\.]+)$/VERSION := {{ version }}/' \
        Makefile
    sed -E -i -e 's/"version": "([0-9\.]+)"/"version": "{{ version }}"/' \
        tree-sitter.json
    sed -E -i -e 's/^version = "([0-9\.]+)"/version = "{{ version }}"/' \
        pyproject.toml
    sed -E -i -e 's/^version = "([0-9\.]+)"/version = "{{ version }}"/' \
        Cargo.toml
    sed -E -i -e 's/  VERSION "([0-9\.]+)"/  VERSION "{{ version }}"/' \
        CMakeLists.txt

# Publish a new release
release version: (update-version version) (changelog version) (commit version) (tag version)
