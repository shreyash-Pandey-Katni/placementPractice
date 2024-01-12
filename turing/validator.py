from typing import Dict

def validate_email_addr(email_addr: str) -> bool:
    """Validate an email address.

    Args:
        email_addr: The email address to validate.

    Returns:
        True if the email address is valid, False otherwise.
    """
    # Leading and trailing whitespace should be ignored.
    email_addr = email_addr.strip()

    # Email addresses must have exactly one @ symbol. 

    if email_addr.count("@") != 1:
        return False

    # Total length should not exceed 254 bytes.

    if len(email_addr) > 254:
        return False 
    # The part before the @ should not exceed 64 bytes.

    local_part, domain_part = email_addr.split("@")
    if len(local_part) > 64:
        return False 
    # The part after the @ should not exceed 251 bytes.
    if len(domain_part) > 251:
        return False 
    # valid characters for an email address include lowercase letters, uppercase letters, digits, @, - and ".". 
    if not all(c in "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@-." for c in email_addr):
        return False
    # Hyphens and dots cannot be the first or last character before @.

    if local_part[0] in "-." or local_part[-1] in "-.":
        return False

    # Email address must end with the top level domain of ".com", ".net" or ".org". 
    if not domain_part.endswith((".com", ".net", ".org")):
        return False
    # Raise a ValueError if the email address is invalid.
    return True

def validateNames(name:str, length:int) -> bool:
    """Validate a name.

    Args:
        name: The name to validate.

    Returns:
        True if the name is valid, False otherwise.
    """
    # Leading and trailing whitespace should be ignored.
    name = name.strip()

    # name must be at least 5 characters long. and not exceed length.
    if len(name) < 5 or len(name) > length:
        return False

    return True

def validateHTMLwithRespectivePlaceholders(html: str, replacements: Dict[str, str]) -> bool:
    """Validate an HTML string.

    Args:
        html: The HTML string to validate.
        replacements: A dictionary of placeholders and their respective values.

    Returns:
        True if the HTML string is valid, False otherwise.
    """
    # Leading and trailing whitespace should be ignored.
    html = html.strip()

    # Replacement values must be non-empty strings.
    for value in replacements.values():
        if not value or value == "":
            return False

    # HTML string must be at least 5 characters long.
    if len(html) < 5:
        return False

    # HTML string must contain all the placeholders.
    for placeholder in replacements.keys():
        if "{"+placeholder+"}" not in html:
            return False

    # List all placeholders in the HTML string. placeholders must be surrounded by curly braces. use regex
    placeholders = []
    for i in range(len(html)):
        if html[i] == "{":
            placeholders.append(html[i+1:html.find("}", i+1)])
    
    if placeholders != list(replacements.keys()):
        return False
    return True