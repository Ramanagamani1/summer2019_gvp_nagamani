from django import forms

class LoginForm(forms.Form):
        username=forms.CharField(required=True,
                    max_length=75,
                    widget=forms.TextInput(attrs={'class':'input','placeholder':'enter username'})
                                 )
        password=forms.CharField(
                    required=True,
            max_length=75,
                   widget=forms.PasswordInput(attrs={'class':'input','placeholder':'enter password' })
                                )

class SignupForm(forms.Form):
         first_name=forms.CharField(required=True,
                                   max_length=75,
                      widget=forms.TextInput(attrs={'class':'input','placeholder':'enter firstname'})
                                   )
         last_name=forms.CharField(required=True,
                                  max_length=75,
                      widget=forms.TextInput(attrs={'class':'input','placeholder':'enter lastname'})
                                   )
         username=forms.CharField(required=True,
                                  max_length=75,
                    widget=forms.TextInput(attrs={'class':'input','placeholder':'enter username'})
                                  )
         password = forms.CharField(
             max_length=75,
             widget=forms.PasswordInput(attrs={'class':'input','placeholder': 'enter password'})
         )